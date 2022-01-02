# Zones with (offset) - ZoneUSEastern (-5), Central(-6), Mountains(-7), Pacific(-8)
# Zone properties - displayName, offset, zoneID
# Zone methods - getDisplayName(), getOffset()

from abc import ABCMeta, abstractmethod



class Zone(metaclass=ABCMeta):

    displayName, offset = "", 0
    def getDisplayName(self):
        return self.displayName
    def getOffset(self):
        return self.offset

class ZoneFactory():

    def __init__(self,zoneID):
        self.zoneID = zoneID

    def createZone(self):
        if self.zoneID == "ET":
            return ZoneUSEastern()
        elif self.zoneID == "CN":
            return ZoneUSCentral()
        elif self.zoneID == "MT":
            return ZoneUSMountain()
        elif self.zoneID == "PF":
            return ZoneUSPacific()

class ZoneUSEastern(Zone):
    displayName = "US Eastern Zone"
    offset = -5

class ZoneUSCentral(Zone):
    displayName = "US Central Zone"
    offset = -6

class ZoneUSMountain(Zone):
    displayName = "US Mountain Zone"
    offset = -7

class ZoneUSPacific(Zone):
    displayName = "US Pacific Zone"
    offset = -8

class Calendar(metaclass=ABCMeta):
    zone = None
    def printer(self):
        print("Name of zone : ", self.zone.getDisplayName())
        print("Offset : ", str(self.zone.getOffset()))
        

    @abstractmethod
    def createCalendar(self):
        pass


class PacificCalendar(Calendar):
    zoneId = "PF"
    def createCalendar(self):
        getZone = ZoneFactory(self.zoneId)
        self.zone = getZone.createZone()
        

if __name__ == "__main__":
    cal = PacificCalendar()
    cal.createCalendar()
    cal.printer()

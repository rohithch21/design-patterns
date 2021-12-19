from abc import ABC, abstractmethod, ABCMeta

class Drone(metaclass = ABCMeta):

    @abstractmethod
    def beep(self):
        pass

    @abstractmethod
    def spin_rotors(self):
        pass

    @abstractmethod
    def take_off(self):
        pass

class SuperDrone(Drone):
    def beep(self):
        print("Beep beep beep")
    def spin_rotors(self):
        print("Rotors are spinning")
    def take_off(self):
        print("Taking Off")

class Duck(metaclass=ABCMeta):
    @abstractmethod
    def quack(self):
        pass

    @abstractmethod
    def fly(self):
        pass

class MallardDuck(Duck):
    def quack(self):
        print("Mallard Duck quack!")
    
    def fly(self):
        print("Mallard Duck NO FLY!")
    
class duckSimulator():
    def __init__(self, duckObj) -> None:
        self.duck = duckObj

    def testDuck(self):
        self.duck.quack()
        self.duck.fly()

class DroneAdapter(Duck):

    def __init__(self, droneItfObj) -> None:
        self.drone = droneItfObj
    def quack(self):
        self.drone.beep()
    def fly(self):
        self.drone.spin_rotors()
        self.drone.take_off()

if __name__ == "__main__":
    mySuperDrone = SuperDrone()
    sim = duckSimulator(DroneAdapter(mySuperDrone)) # Pass the adapter class which implements the target interface Duck using Drone methods
    sim.testDuck()
    myDuck = MallardDuck()
    sim2 = duckSimulator(myDuck)
    sim2.testDuck()


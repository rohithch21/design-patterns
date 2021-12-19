from abc import ABCMeta, abstractmethod

# abstract class 
class Pizza(metaclass=ABCMeta):
    description = "Unknown Beverage"

    def getDescription(self):
        return self.description

    @abstractmethod
    def cost(self):
        pass

class ThinCrustPizza(Pizza):
    description = "Thin crust pizza"
    def cost(self):
        return 10
class ThickCrustPizza(Pizza):
    description = "Thick crust pizza"

    def cost(self):
        return 5

class ToppingDecorator(Pizza, metaclass=ABCMeta):
    @abstractmethod
    def getDescription(self):
        pass

class CheeseTopping(ToppingDecorator):
    # pizza = Pizza()
    def __init__(self, pizzaObj):
        self.pizza = pizzaObj
    def getDescription(self):
        return self.pizza.getDescription() + ", cheese"
    def cost(self):
        return self.pizza.cost() + 0.99

class OliveTopping(ToppingDecorator):
    def __init__(self, pizzaObj):
        self.pizza = pizzaObj
    def getDescription(self):
        return self.pizza.getDescription() + ", olives"
    def cost(self):
        return self.pizza.cost() + 1


if __name__ == "__main__":
    p = ThinCrustPizza()
    p = OliveTopping(p)
    p = CheeseTopping(p)
    print(p.getDescription() + " $ " + str(p.cost()))



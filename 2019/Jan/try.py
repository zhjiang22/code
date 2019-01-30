class Restaurant:
    def __init__(self, restaurant_name, cuisine_type, number_served=0):
        self.restaurant_name = restaurant_name
        self.cuisine_type = cuisine_type
        self.number_served = number_served
    def describe_restaurant(self):
        print('The name: %s' % self.restaurant_name)
        print('The type: %d' % self.cuisine_type)
        print('The number: %d' % self.number_served)
    def open_restaurant(self):
        print('The restaurant is working now')
    def set_number_served(self, numbers):
        self.number_served = numbers
        print('The number: %d' % self.number_served)
    def increment_number_served(self, numbers=1):
        self.number_served += numbers
        print('The number: %d' % self.number_served)
    def reset_number_served(self):
        self.number_served = 0
        print('The number: %d' % self.number_served)

restaurant = Restaurant('PowderHan\'s restaurant', 1)
restaurant.describe_restaurant()
restaurant.open_restaurant()
restaurant.set_number_served(5)
restaurant.increment_number_served(4)
restaurant.increment_number_served(4)
restaurant.reset_number_served()
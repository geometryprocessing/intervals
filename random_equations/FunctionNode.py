class FunctionNode:
    # either a node or a leaf, it requires either 1 or 2 children
    def __init__(self, variable_count):
        self.variable_count = variable_count
        self.lowerOutputBound = float('-inf')
        self.upperOutputBound = float('inf')
        self.leftLowerInputBound = float('-inf')
        self.leftUpperInputBound = float('inf')
        self.leftFalseRegion = []
        self.rightLowerInputBound = float('-inf')
        self.rightUpperInputBound = float('inf')
        self.rightFalseRegion = []

    # define how the to string method will be defined
    def setStringMethod(self, method):
        self.toStringMethod = method

    # define how the queue will be printed
    def setQueueStringMethod(self, method):
        self.toQueueMethod = method

    # define upper and lower bounds
    def leftInputBound(self, lower, upper):
        self.leftLowerInputBound = lower
        self.leftUpperInputBound = upper

    def rightInputBound(self, lower, upper):
        self.rightLowerInputBound = lower
        self.rightUpperInputBound = upper

    def outputBound(self, lower, upper):
        self.lowerOutputBound = lower
        self.upperOutputBound = upper

    # print out the method
    def toMethodString(self, children_string):
        return self.toStringMethod(children_string)

    # print out the queue
    def toQueueString(self, children_string):
        return self.toQueueMethod(children_string)

    # false regions, the ones that the input should not be
    # for example, for division, it cannot be 0 for denominator
    def setLeftFalseRegion(self, regions):
        self.leftFalseRegion = regions

    def setRightFalseRegion(self, regions):
        self.rightFalseRegion = regions


# addition
def add_method_string(children_string):
    return children_string[0] + "+" + children_string[1]


def add_queue_string(children_string):
    return children_string[0] + ' + "+" + ' + children_string[1]


add_method = FunctionNode(2)
add_method.setStringMethod(add_method_string)
add_method.setQueueStringMethod(add_queue_string)


# subtraction
def subtract_method_string(children_string):
    return children_string[0] + "-" + children_string[1]


def subtract_queue_string(children_string):
    return children_string[0] + ' + "-" + ' + children_string[1]


subtract_method = FunctionNode(2)
subtract_method.setStringMethod(subtract_method_string)
subtract_method.setQueueStringMethod(subtract_queue_string)


# multiplication
def multiply_method_string(children_string):
    return "(" + children_string[0] + ") * (" + children_string[1] + ")"


def multiply_queue_string(children_string):
    return '"(" + ' + children_string[0] + ' + ")" + "*" + "(" + ' + children_string[1] + '+ ")"'


multiply_method = FunctionNode(2)
multiply_method.setStringMethod(multiply_method_string)
multiply_method.setQueueStringMethod(multiply_queue_string)


# division
def divide_method_string(children_string):
    return "(" + children_string[0] + ") / (" + children_string[1] + ")"


def divide_queue_string(children_string):
    return '"(" + ' + children_string[0] + ' + ")" + "/" + "(" + ' + children_string[1] + '+ ")"'


divide_method = FunctionNode(2)
divide_method.setStringMethod(divide_method_string)
divide_method.setQueueStringMethod(divide_queue_string)
divide_method.setRightFalseRegion([" == 0"])


# square root
def square_root_method_string(children_string):
    return "sqrt("+children_string[0]+")"


def square_root_queue_string(children_string):
    return '"Sqrt" + "(" + '+children_string[0]+' + ")"'


square_root_method = FunctionNode(1)
square_root_method.leftInputBound(0, float('inf'))
square_root_method.outputBound(0, float('inf'))
square_root_method.setStringMethod(square_root_method_string)
square_root_method.setQueueStringMethod(square_root_queue_string)


# exponential
def exponential_method_string(children_string):
    return "exp("+children_string[0]+")"


def exponential_queue_string(children_string):
    return '"Exp" + "(" + '+children_string[0]+' + ")"'


exponential_method = FunctionNode(1)
exponential_method.leftInputBound(-700, 700)
exponential_method.outputBound(0, float('inf'))
exponential_method.setStringMethod(exponential_method_string)
exponential_method.setQueueStringMethod(exponential_queue_string)


# sin
def sin_method_string(children_string):
    return "sin("+children_string[0]+")"


def sin_queue_string(children_string):
    return '"sin" + "(" + '+children_string[0]+' + ")"'


sin_method = FunctionNode(1)
sin_method.outputBound(-1, 1)
sin_method.setStringMethod(sin_method_string)
sin_method.setQueueStringMethod(sin_queue_string)


# cos
def cos_method_string(children_string):
    return "cos("+children_string[0]+")"


def cos_queue_string(children_string):
    return '"cos" + "(" + '+children_string[0]+' + ")"'


cos_method = FunctionNode(1)
cos_method.outputBound(-1, 1)
cos_method.setStringMethod(cos_method_string)
cos_method.setQueueStringMethod(cos_queue_string)


# leaf node
def leaf_method_string(children_string):
    return "value_array["+str(children_string[0])+"]"


def leaf_queue_string(children_string):
    return "rational_to_string(value_array[" + str(children_string[0]) + "])"


leaf_method = FunctionNode(0)
leaf_method.setStringMethod(leaf_method_string)
leaf_method.setQueueStringMethod(leaf_queue_string)


# put all available methods here
# always put the leaf method to the end
available_methods = [add_method, subtract_method, multiply_method, divide_method,
                     square_root_method, exponential_method, sin_method, cos_method, leaf_method]

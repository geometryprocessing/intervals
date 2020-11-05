from FunctionNode import available_methods
import random


class TreeNode:
    def __init__(self, functionNode, level):
        self.functionNode = functionNode
        self.childrenCount = functionNode.variable_count
        self.level = level
        self.leftChild = None
        self.rightChild = None

    # if the children count is 0, this will be the variable index
    # else, this will be the actual child
    def setLeftChild(self, treeNode):
        self.leftChild = treeNode

    def setRightChild(self, treeNode):
        if self.childrenCount > 1:
            self.rightChild = treeNode

    def setLeafBound(self, lower, upper):
        self.leafLowerBound = lower
        self.leafUpperBound = upper

    def toMethodString(self):
        # if this is a leaf node
        if (self.childrenCount == 0):
            return self.functionNode.toMethodString([str(self.leftChild)])
        elif (self.childrenCount == 1):
            leftString = self.leftChild.toMethodString()
            return self.functionNode.toMethodString([leftString])
        else:
            leftString = self.leftChild.toMethodString()
            rightString = self.rightChild.toMethodString()
            return self.functionNode.toMethodString([leftString, rightString])

    def toQueueString(self):
        if (self.childrenCount == 0):
            return self.functionNode.toQueueString([str(self.leftChild)])
        elif (self.childrenCount == 1):
            leftString = self.leftChild.toQueueString()
            return self.functionNode.toQueueString([leftString])
        else:
            leftString = self.leftChild.toQueueString()
            rightString = self.rightChild.toQueueString()
            return self.functionNode.toQueueString([leftString, rightString])

    def generateFalseRegion(self):
        falseRegionsStrings = []
        if self.childrenCount > 0:
            input_left_lower = self.leftChild.functionNode.lowerOutputBound
            input_left_upper = self.leftChild.functionNode.upperOutputBound
            # print(input_left_lower, input_left_upper)
            if (input_left_lower < self.functionNode.leftLowerInputBound):
                falseRegionsStrings.append(
                    self.leftChild.toMethodString() + " < " + str(self.functionNode.leftLowerInputBound))
            if (input_left_upper > self.functionNode.leftUpperInputBound):
                falseRegionsStrings.append(
                    self.leftChild.toMethodString() + " > " + str(self.functionNode.leftUpperInputBound))
            if len(self.functionNode.leftFalseRegion) > 0:
                # print(self.functionNode.leftFalseRegion)
                for item in self.functionNode.leftFalseRegion:
                    falseRegionsStrings.append(
                        self.leftChild.toMethodString() + item)

        if self.childrenCount > 1:
            input_right_lower = self.rightChild.functionNode.lowerOutputBound
            input_right_upper = self.rightChild.functionNode.upperOutputBound
            if (input_right_lower < self.functionNode.rightLowerInputBound):
                falseRegionsStrings.append(
                    self.rightChild.toMethodString() + " < " + input_right_lower)
            if (input_right_upper > self.functionNode.rightUpperInputBound):
                falseRegionsStrings.append(
                    self.rightChild.toMethodString() + " > " + input_right_lower)
            if len(self.functionNode.rightFalseRegion) > 0:
                # print(self.functionNode.rightFalseRegion)
                for item in self.functionNode.rightFalseRegion:
                    falseRegionsStrings.append(
                        self.rightChild.toMethodString() + item)
        return falseRegionsStrings

    def generateAllFalseRegion(self):
        if self.childrenCount == 0:
            return []
        elif self.childrenCount == 1:
            return self.leftChild.generateAllFalseRegion() + self.generateFalseRegion()
        else:
            return self.leftChild.generateAllFalseRegion() + self.rightChild.generateAllFalseRegion() + self.generateFalseRegion()


# the equation tree
class EQTree:
    def __init__(self, variable_count, level, functionBaseName):
        self.variables = list(range(variable_count))
        random.shuffle(self.variables)
        self.variables_limit = []
        for _ in range(variable_count):
            self.variables_limit.append([float("-inf"), float("inf")])
        self.variable_count = variable_count
        self.level = level
        self.root = TreeNode(random.choice(available_methods[:-1]), 0)
        self.functionBaseName = functionBaseName
        self.fillTree()

    def fillTree(self):
        nodesThatNeedChildren = [self.root]
        while len(nodesThatNeedChildren) > 0:
            node = nodesThatNeedChildren.pop(0)
            num_children = node.childrenCount
            node_level = node.level
            # if this is a leaf node, we randomly assign a number from variables to it
            if num_children == 0:
                # randomly choose a variable for it
                used_variable = self.variables.pop(0)
                if len(self.variables) == 0:
                    self.variables = list(range(self.variable_count))
                    random.shuffle(self.variables)
                node.setLeftChild(used_variable)
                if node.leafLowerBound > self.variables_limit[used_variable][0]:
                    self.variables_limit[used_variable][0] = node.leafLowerBound
                if node.leafUpperBound < self.variables_limit[used_variable][1]:
                    self.variables_limit[used_variable][1] = node.leafUpperBound
            else:
                # this is not a leaf node
                if node_level == self.level - 1:
                    # our children has to be leaf nodes
                    leftLeaf = TreeNode(available_methods[-1], self.level)
                    node.setLeftChild(leftLeaf)
                    nodesThatNeedChildren.append(leftLeaf)
                    if num_children > 1:
                        rightLeaf = TreeNode(available_methods[-1], self.level)
                        node.setRightChild(rightLeaf)
                        nodesThatNeedChildren.append(rightLeaf)
                else:
                    # our children can be anything
                    leftLeaf = TreeNode(random.choice(
                        available_methods), node_level+1)
                    node.setLeftChild(leftLeaf)
                    nodesThatNeedChildren.append(leftLeaf)
                    if num_children > 1:
                        rightLeaf = TreeNode(random.choice(
                            available_methods), node_level+1)
                        node.setRightChild(rightLeaf)
                        nodesThatNeedChildren.append(rightLeaf)
                # ok, if our children is a leaf, we need to pass the input bound to it
                # might as well just say the children are vegetable
                if node.leftChild.childrenCount == 0:
                    node.leftChild.setLeafBound(
                        node.functionNode.leftLowerInputBound, node.functionNode.leftUpperInputBound)
                if num_children > 1:
                    if node.rightChild.childrenCount == 0:
                        node.rightChild.setLeafBound(
                            node.functionNode.rightLowerInputBound, node.functionNode.rightUpperInputBound)

    def toMethodString(self):
        return self.root.toMethodString()

    def toQueueString(self):
        return self.root.toQueueString()

    def generateAllFalseRegion(self):
        return self.root.generateAllFalseRegion()

    def variableBoundaries(self):
        return self.variables_limit

    def toCMethodString(self):
        s = ""
        s += "template <class T>\ninline T "
        s += self.functionBaseName
        s += "(const std::vector<T> &value_array)"
        s += "\n{\n    return "
        s += self.toMethodString()
        s += ";\n}\n"
        return s

    def toCQueueString(self):
        s = ""
        s += "std::string print_"
        s += self.functionBaseName
        s += "(const std::vector<gmp::Rational> &value_array)"
        s += "\n{\n    return std::string() + "
        s += self.toQueueString()
        s += ";\n}\n"
        return s

    def toCCheckString(self):
        s = ""
        s += "bool check_input_"
        s += self.functionBaseName
        s += "(const std::vector<double> &value_array)"
        s += "\n{\n"
        falseRegions = dict.fromkeys(self.generateAllFalseRegion())
        for item in falseRegions:
            s += "    if ("
            s += item
            s += ")\n        return false;\n"
        s += "    return true;\n}\n"
        return s

    def toCVariableRange(self):
        s = ""
        s += "const std::vector<std::uniform_real_distribution<double>> "
        s += self.functionBaseName
        s += "_range = {"
        vb = self.variableBoundaries()
        for item in vb:
            lower = item[0]
            upper = item[1]
            lower_string = str(lower)
            upper_string = str(upper)
            if (lower == float("-inf")):
                lower_string = "-RAND_MAX + 1"
            if (upper == float("inf")):
                upper_string = "RAND_MAX"
            s += "std::uniform_real_distribution<double>("
            s += lower_string
            s += ", "
            s += upper_string
            s += "), "
        s = s[:-2]
        s += "};\n"
        return s

    def generateCStrings(self):
        s = "// Generated function strings for "
        s += self.functionBaseName
        s += "\n"
        s += self.toCMethodString()
        s += self.toCQueueString()
        s += self.toCCheckString()
        s += self.toCVariableRange()
        s += "const int "
        s += self.functionBaseName
        s += "_variable_count = "
        s += str(self.variable_count)
        s += ";\n"
        return s


root = EQTree(6, 6, "extra_function1")
print(root.generateCStrings())


# root = TreeNode(available_methods[4], 0)
# child = TreeNode(available_methods[6], 1)
# leaf = TreeNode(available_methods[-1], 2)
# leaf.setLeftChild('1')
# child.setLeftChild(leaf)
# root.setLeftChild(child)
# print(root.generateAllFalseRegion())

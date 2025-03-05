class Person:
    def __init__(self, name: str) -> None:
        # store in upper case for consistency
        self.name = name.upper()
        self.children = []

    def add_child(self, child: "Person") -> None:
        self.children.append(child)

    def __repr__(self):
        return self.name


class FamilyTree:
    def __init__(self, root_name: str) -> None:
        # Ancestor of the family
        self.root = Person(root_name)

    def find_person(self, name: str, node: Person) -> Person | None:
        if not node:
            # Empty family tree
            return None
        if node.name == name.upper():
            return node
        for child in node.children:
            found = self.find_person(name, child)
            if found:
                return found
        return None

    def add_child(self, parent_name: str, child_name: str) -> Person:
        """Add child to given parent"""
        parent = self.find_person(parent_name, self.root)
        if parent:
            parent.children.append(Person(child_name))
        else:
            print(f"Parent {parent_name} not found")

    def display(self, node=None, level=0):
        """Display the family tree as an indented hierarchy."""
        if node is None:
            node = self.root
        print("  " * level + f"└─ {node.name}")
        for child in node.children:
            self.display(child, level + 1)


def main():
    print("Welcome to Family Tree Manager!")
    root_name = input("Enter the name of the first ancestor: ")
    tree = FamilyTree(root_name)

    while True:
        print("\nMenu:")
        print("1. Add Family Member")
        print("2. Display Family Tree")
        print("3. Exit")
        choice = input("Enter your choice: ")

        if choice == "1":
            parent = input("Enter parent’s name: ")
            child = input("Enter child's name: ")
            tree.add_child(parent, child)
        elif choice == "2":
            print("\nFamily Tree:")
            tree.display()
        elif choice == "3":
            print("Exiting... Goodbye!")
            break
        else:
            print("Invalid choice, try again.")


if __name__ == "__main__":
    main()

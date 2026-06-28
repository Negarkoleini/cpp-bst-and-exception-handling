# C++ Advanced Practices: Binary Search Tree & Exception Handling

Welcome to this specialized C++ development repository. This repository focuses on the practical implementation of custom generic containers—specifically a **Binary Search Tree (BST)**—and the architectural deployment of modern C++ **Exception Handling** strategies to replace unsafe runtime flows.

---

## 📂 Repository Structure & Project Modules

The codebase is organized into three distinct, interconnected modules that demonstrate how custom containers, design patterns, and exception safety work together:

### 1. 🛡️ Safe Template Array (`01-Safe-Template-Array`)
* **What it Does:** A custom implementation of a fixed-size array container (`FixedArray<T>`) using generic programming (`template`). It overloads the subscript operator (`[]`) to create a safer alternative to raw C-style arrays.
* **How it works & Exceptions:** It eliminates buffer overflows and unsafe segmentation faults by validating indices. It actively throws a `std::out_of_range` exception whenever a subscript falls out of bounds (negative or greater than size).

### 2. 🌲 Generic Binary Search Tree Container (`02-Generic-BST-Container`)
* **What it Does:** Implements a dynamic Binary Search Tree (BST) from scratch capable of holding any data type that supports comparison operators. It features standard tree operations such as `insert`, `find`, and `remove` via pointer manipulation and handles hierarchical in-order traversals (`inorder`).
* **How it works & Exceptions:** This module enforces structural integrity by checking operations at runtime and throwing `std::runtime_error` exceptions under these conditions:
  * Attempting to insert a duplicate value that already exists in the BST.
  * Trying to locate an element via `find()` that cannot be resolved in the tree.
  * Attempting to remove a non-leaf node, enforcing strict structural deletion rules.

### 3. 🌌 Cosmic Singleton Universe & Apple Pie Simulation (`03-Cosmic-Singleton-Universe`)
* **What it Does:** A fascinating ecosystem simulation centered around a creational cosmic container (`Universe`) managing dynamically allocated objects (`Creation`) like `Human` and `Apple`. It guarantees a single global state of the world by enforcing the **Singleton Design Pattern** (ensuring only one instance of the `Universe` exists).

#### 🥧 Deep Dive: The Apple Pie Feature (`bakeApplePie()`)
The universe includes a specialized method called `bakeApplePie()` which simulates a complex polymorphic interaction. Here is exactly how it operates step-by-step:
1. **Polymorphic Scanning:** The `Universe` iterates through its internal database of `Creation*` pointers.
2. **Safe Downcasting:** Since the database holds base class pointers, the system uses `static_cast<Human*>` and `static_cast<Apple*>` to safely inspect the derived types and look for domain-specific attributes.
3. **Condition Verification:** * It counts how many `Human` entities are **alive** (`getIsAlive() == true`).
   * It counts how many `Apple` entities are **not rotten** (`getIsRotten() == false`).
4. **The Exception Threshold:** * If there is **no living human** in the universe, or **no fresh apple** available, the simulation fails defensively and throws a **`std::runtime_error`** stating that the dependencies for baking are missing.
   * If both conditions are successfully met, it instantiates and returns a new **`ApplePie`** object marked as *delicious* (`isDelicious = true`).

#### ⚠️ Complete Exception Hierarchy in Universe Module:
* **`std::invalid_argument`:** * Thrown inside `Date` if the initialization numbers are broken (e.g., month > 12 or day > 30).
  * Thrown inside `Human` if an empty string `""` is passed as a name.
  * Thrown inside `Apple` if an empty string `""` is passed as the color.
  * Thrown inside `Universe::addCreation` if you try to add a `nullptr`.
* **`std::length_error`:** Thrown if a human's name exceeds character constraints (e.g., length > 15).
* **`std::bad_alloc`:** Thrown inside `Universe::addCreation` if the universe reaches its maximum tracking capacity.
* **`std::logic_error`:** Thrown inside `Universe::deleteCreation` if you attempt to delete an entity using an invalid or non-existent ID.
* **`std::runtime_error`:** Thrown inside `bakeApplePie()` when baking logic requirements fail (no living human or no fresh apple).

---

## 🛡️ Focus Feature: Defensive Architecture via Exceptions

Rather than using basic console prints (`std::cout`) or aggressive assertions that terminate programs unexpectedly, this entire repository is built on a defensive programming foundation using the `<stdexcept>` and `<exception>` headers. 

Every container mutation, look-up failure, or incorrect instantiation is wrapped inside clear `try-catch` testing suites located in each module's `main.cpp` file, proving that the application state remains safe, informative, and retrievable even during severe runtime errors.

---

## 🚀 How to Build and Run

### Prerequisites
* A C++ compiler supporting at least the **C++17** standard (GCC, Clang, or MSVC).

### Compilation Example (via Command Line)
Navigate to the specific directory and compile using your compiler toolchain:

```bash
# Compiling and running the Binary Search Tree module
cd 02-Generic-BST-Container
g++ -std=c++17 week4s1.cpp -o bst_demo
./bst_demo

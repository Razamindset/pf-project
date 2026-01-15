# Minilang Transpiler

A lightweight source-to-source compiler that converts **Minilang** (a simplified custom language) into **C++** code.

## 🚀 Recent Updates: Strong Typing

Initially, Minilang used a generic `let` keyword which mapped to C++ `auto`. To improve code stability and support more data types, the language now uses explicit type keywords:

| Minilang Keyword | C++ Equivalent | Description |
| --- | --- | --- |
| `num` | `int` | For whole numbers. |
| `decimal` | `double` | For floating-point numbers. |
| `letter` | `char` | For single characters. |

## 🛠️ Features

* **Variable Declaration:** Explicitly define integers, doubles, and chars.
* **Print/Input:** Simple syntax for standard I/O.
* **Control Flow:** Supports `if`, `else`, and `repeat` (while) loops.
* **Comments:** Use `#` for documentation, which is converted to C++ `//` comments.
* **Auto-Compile:** Automatically triggers `g++` to compile the output.

## 📂 Syntax Example

Create a file named `test.minilang`:

```python
# This is a test program
num age = 20
decimal price = 9.99
letter grade = 'A'

print "Enter a new age:"
input age

if age > 18 {
    print "You are an adult"
}
else {
    print "You are a minor"
}

repeat age < 25 {
    age = age + 1
    print age
}

```

## 💻 How to Run

1. Compile the transpiler:
`g++ main.cpp -o minilang.exe`
2. Run your code:
`./minilang.exe test.minilang`

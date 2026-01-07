## 📄 MiniLang → C++ Transpiler

A simple transpiler written in C++ that converts a custom teaching language (“MiniLang”) into valid C++ code and executes it.

This project is meant for **learning purposes**, not production compilers. It **does not use lexers/parsers/ASTs**. Instead it performs simple **line-based pattern translation** using `<regex>` and string operations.

---

## ✨ Language Features

MiniLang supports:

* variable declaration
* assignment
* arithmetic expressions
* `print`
* `input`
* `if` and `else`
* `repeat` loop (translated to `while`)
* comments using `#`
* automatic typing via `auto`

---

## 🧾 Syntax Reference

### ✔ Variable Declaration

```
let a = 10
let name = 5 + 9
```

Transpiles to:

```
auto a = 10;
```

---

### ✔ Printing Output

```
print a
print 5 + 9
print "hello"
```

Becomes:

```
cout << a << endl;
```

---

### ✔ Input from User

```
input a
```

Becomes:

```
cin >> a;
```

---

### ✔ If Statement

```
if a == 10 {
    print a
}
```

Translates to:

```
if(a == 10){
    cout << a << endl;
}
```

---

### ✔ If–Else Statement

```
if a == 5 {
    print 1
}
else {
    print 0
}
```

---

### ✔ Loop (repeat while condition)

```
repeat a < 10 {
    print a
    a = a + 1
}
```

Translates to:

```
while(a < 10){
    cout << a << endl;
    a = a + 1;
}
```

---

### ✔ Assignment

```
a = 5
a = a + 1
```

---

### ✔ Comments

```
# This is ignored
# like python comments
```

---

## 🛠 How It Works Internally

1. Read `.urdu` or `.minilang` file line-by-line
2. Remove leading/trailing spaces
3. Match patterns using:

   * `let` for variable declarations
   * `print` for output
   * `input` for user input
   * `if`, `else`, `repeat` constructs
4. Maintain manual indent level for blocks
5. Write C++ to `output.cpp`
6. Auto-compile using `g++`
7. Execute generated program

---

## ▶ How To Run

```
g++ main.cpp -o transpiler
./transpiler program.minilang
```

It will:

* generate `output.cpp`
* compile it
* run final executable

---

## 🧪 Example Programs

---

### 📝 Example 1 — Basic If / Else

**program.minilang**

```
let a = 10
print a

if a == 25 {
    print a
}
else {
    print 69
}
```

---

### 📝 Example 2 — Repeat Loop Counter

```
let i = 0

repeat i < 5 {
    print i
    i = i + 1
}
```

---

### 📝 Example 3 — Input + Condition

```
let age = 0
input age

if age >= 18 {
    print "adult"
}
else {
    print "minor"
}
```

---

### 📝 Example 4 — Sum 1 to N

```
let n = 0
let sum = 0

input n

repeat n > 0 {
    sum = sum + n
    n = n - 1
}

print sum
```

---

### 📝 Example 5 — Multiplication Table

```
let i = 1
let n = 5

repeat i <= 10 {
    print n * i
    i = i + 1
}
```

---

## 🚧 Current Limitations

* no functions
* no arrays
* single-line syntax preferred
* requires `{` and `}` exactly like C-style
* basic error handling only
* whitespace sensitive in some cases

---

## 🛣 Possible Future Improvements

* add `for` loops
* add functions
* add `== != >= <=`
* boolean keywords `true / false`
* strings stored in variables
* custom types
* simple lexer/tokenizer
* error messages with line numbers

---
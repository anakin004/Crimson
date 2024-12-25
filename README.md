# Crimson

![Crimson](https://github.com/user-attachments/assets/98d28dcd-90af-47fc-bce6-0f9f80035d13)

# Crimson Engine

Crimson is an open-source game engine currently under development including 2D and 3D environments
imported tools used are found in the Crimson/vendor directory

---

## 🚀 Features (so far)

- **Cross-Platform Support**: Designed to run on multiple platforms.
- **Spdlog**: logging debug and program-tracing info
- **ImGui**: UI for runtime testing
- **GLFW**: Used to create windows, contexts, receiving input, and call-backs
- **Glad**: loading OpenGL functions into Crimson
- **Math Library**: Developed my own math library, Chroma.
  relevant snipets and inspiration accredited to the YouTube channel GetIntoGameDev
- **Compiler Support (Work in Progress)**: 
  - GCC, Cmake, MSVC support SIMD operations
  - working on including more

---

## 🛠️ Getting Started

### Prerequisites
Before building Crimson, ensure your system meets the following requirements:

- **C++ Compiler**: Supports C++17 or higher (GCC or MSVC recommended)
- **CMake**: Version 3.15 or higher
- **Git**: For cloning the repository and managing submodules

---

### Installation

Follow these steps to set up the project:

1. **Clone the Repository**:

   Clone Crimson along with its submodules:
   ```bash
   git clone --recursive https://github.com/anakin004/Crimson.git

### Generate Project Files

Navigate to the repository directory and execute the provided script:  
```bash
cd Crimson
./GenerateProjects.bat
```
### Building

Currently toned towards msvc, 
will soon include docs for cmake, gcc, etc


## 💻 Contributing

We welcome contributions to Crimson! To contribute:  
1. Fork the repository 
2. Create a new branch for your feature or fix
3. Commit your changes with detailed messages
4. Submit a pull request  

Please include as much documentation as possible in any commits!!

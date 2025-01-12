# Crimson 


![Crimson](https://github.com/user-attachments/assets/fae28d60-1330-4bae-acab-57e12994e7f2)


# Crimson Engine 

# IMPORTANT: I decided to work in a development repository apart from this. There is going to be doing a big release of Crimson in the upcomming weeks! It will be including a full 3D renderer, 3D renderer will likely come first and then the 2D renderer, libraries like Box2D, Physx, yaml-cpp, assimp, and some networking multiplayer stuff soon after! If you are seeing this watch my repository! I am very excited for this upcomming release!

Crimson is an open-source game engine currently under development including 2D and 3D environments
imported tools used are found in the Crimson/vendor directory

---

## 🚀 Features (so far)

- **Cross-Platform Support**: Designed to run on multiple platforms.
- **Spdlog**: logging debug and program-tracing info
- **ImGui**: UI for runtime testing
- **GLFW**: Used to create windows, contexts, receiving input, and call-backs
- **Glad**: loading OpenGL functions into Crimson
- **Math Library**: Developed my own math library, Chroma(https://github.com/anakin004/Chroma)
  relevant snipets and inspiration accredited to the YouTube channel GetIntoGameDev
- **Compiler Support (Work in Progress)**: 
  - GCC, Cmake, MSVC support SIMD operations
  - working on including more

## Sneak Peak of Crimson(Not Released Yet) ( Demo as of January 12th 2025 )
https://github.com/user-attachments/assets/99ad7c79-45fb-4436-8ec6-fab906d483d9







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

I welcome contributions to Crimson! To contribute:  
1. Fork the repository 
2. Create a new branch for your feature or fix
3. Commit your changes with detailed messages
4. Submit a pull request  

Please include as much documentation as possible in any commits!!

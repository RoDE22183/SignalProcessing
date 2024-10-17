# Waveform Generator

This project is a waveform generator that can create sine, square, and triangle waves. It also includes basic DSP functionality.

## Features

- Generate sine, square, and triangle waves
- Adjustable frequency, amplitude, and phase
- Apply DSP functions
- Save waveform data to CSV files

## Prerequisites

To build and run this project, you need:

- C++ compiler with C++20 support (e.g., GCC 10+, Clang 10+, or Visual Studio 2019+)
- CMake 3.15 or higher
- Conan package manager

## Building the Project

1. Clone the repository:
   ```
   git clone https://github.com/your-username/waveform-generator.git
   cd waveform-generator
   ```

2. Install dependencies using Conan:
   ```
   mkdir build && cd build
   conan install .. --build=missing
   ```

3. Configure the project with CMake:
   ```
   cmake .. -GNinja -DCMAKE_BUILD_TYPE=Release
   ```

4. Build the project:
   ```
   ninja
   ```

## Running the Program

After building, you can run the program from the command line:

```
./waveform_generator-exe
```

Follow the prompts to input the waveform parameters and apply DSP functions if desired.

## Running Tests

To run the test script (if available):

1. Ensure you're in the project root directory
2. Run the test script:
   ```
   test_waveform_generator.bat
   ```

## Project Structure

- `src/`: Source files
  - `main.cpp`: Main program logic
  - `sinwave.cpp`: Sine wave implementation
  - `squarewave.cpp`: Square wave implementation
  - `trianglewave.cpp`: Triangle wave implementation
  - `dsp.cpp`: DSP functions
- `inc/`: Header files
- `cmake/`: CMake modules
- `CMakeLists.txt`: CMake configuration file
- `conanfile.txt`: Conan dependencies file

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

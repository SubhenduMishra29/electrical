# ContactorsSimulation

ContactorsSimulation is a project that simulates the behavior of contactors in an electrical system.

## Project Structure

The project directory is structured as follows:

- `bin/`: This directory will contain the executable file after compilation.
- `header/`: Contains header files for the project.
    - `Contactor.h`: Header file for the Contactor class.
    - `MainContact.h`: Header file for the MainContact class.
    - `AuxiliaryContact.h`: Header file for the AuxiliaryContact class.
    - `Port.h`: Header file for the Port class.
    - `State.h`: Header file for the State class.
- `src/`: Contains source files for the project.
    - `main.cpp`: The main source file where the program execution begins.
    - `Contactor.cpp`: Source file for the implementation of the Contactor class methods.
    - `ContactFunctions.cpp`: Source file for additional functions related to contacts.
- `CMakeLists.txt`: The CMake configuration file for building the project.
- `LICENSE`: The license file for the project.

## Usage

To compile the project, use CMake:

```bash
mkdir build
cd build
cmake ..
make
```

The executable file will be generated in the `bin/` directory.

## License

This project is licensed under the [GNU General Public License (GPL)](LICENSE).

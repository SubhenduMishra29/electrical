
### Program Overview:

The program simulates a basic ladder logic system using C++. It consists of several key components:

1. **Class Design:**
   - Base class `RungElement` and derived classes (`PushButton`, `Contact`, `Coil`, `Bulb`) represent different elements in a ladder logic rung.

2. **Rung Class:**
   - Manages a collection of `RungElement` objects.
   - Provides methods to add elements and evaluate the entire rung.

3. **Simulator Class:**
   - Manages the state of inputs and outputs.
   - Provides methods to set input states, get output states, add rungs, and simulate the ladder logic.

4. **Main Program:**
   - Demonstrates a basic ladder logic simulation using push buttons, contacts, coils, and bulbs.
   - Sets up a circuit with start and stop buttons controlling a motor and a lamp.
   - Simulates the ladder logic by evaluating the rungs and updating the output states accordingly.

5. **CMake Configuration:**
   - Updated `CMakeLists.txt` to include all source and header files.
   - Specifies include directories and target executable for building the project.

### Directory Structure:
/LadderLogicSimulator
/CMakeLists.txt
/main.cpp
/simulator.h
/simulator.cpp
/rung.h
/rung.cpp
/pushbutton.h
/pushbutton.cpp
/contact.h
/contact.cpp
/coil.h
/coil.cpp
/bulb.h
/bulb.cpp

### Usage:

1. **Build the Project:**
   - Navigate to the project directory and create a build directory.
   - Run CMake to configure the project.
   - Build the project using the generated build system (e.g., make).

2. **Run the Executable:**
   - Execute the generated executable (e.g., `./LadderLogicSimulator`).

3. **Output:**
   - The program will simulate the ladder logic and display the state of outputs (e.g., motor and lamp) based on the input conditions (e.g., start and stop buttons).

### Conclusion:

The program provides a foundation for simulating ladder logic systems and can be extended to handle more complex logic and additional components. It demonstrates the use of object-oriented design principles and C++ features to model and simulate real-world control systems.

########################################################################ver 1.08
### Files Worked On:

1. **rung_element.h**:
   - Added methods for managing connections (`connectTo`, `disconnectFrom`, `isConnectedTo`).
   - Added a protected member `connections` to store connections to other rung elements using `Wire` objects.

2. **bulb.h** and **bulb.cpp**:
   - Updated the `Bulb` class to include methods for managing connections using `Wire` objects.

3. **coil.h** and **coil.cpp**:
   - Updated the `Coil` class to include methods for managing connections using `Wire` objects.

4. **contact.h** and **contact.cpp**:
   - Updated the `Contact` class to include methods for managing connections using `Wire` objects.

5. **pushbutton.h** and **pushbutton.cpp**:
   - Updated the `PushButton` class to include methods for managing connections using `Wire` objects.

6. **wire.h** and **wire.cpp** (if implemented):
   - Introduced a `Wire` class to represent connections between rung elements.


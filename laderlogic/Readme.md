
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
####################################################################3
## File: rung.h

### Methods:

- `void addElement(std::shared_ptr<RungElement> element)`: Adds a RungElement to the rung.
- `bool evaluate(std::unordered_map<std::string, bool>& states)`: Evaluates the rung based on the current states.
- `bool checkContinuity()`: Checks continuity within the rung's rails.

## File: rung_element.h

### Methods:

- `virtual bool evaluate(std::unordered_map<std::string, bool>& states) = 0`: Virtual method to evaluate the rung element.
- `virtual std::string getName() const = 0`: Virtual method to get the name of the rung element.
- `virtual ~RungElement() = default`: Virtual destructor for the rung element.
- `virtual void connectTo(std::shared_ptr<RungElement> element)`: Method to connect to another rung element.
- `virtual void disconnectFrom(std::shared_ptr<RungElement> element)`: Method to disconnect from another rung element.
- `virtual bool isConnectedTo(std::shared_ptr<RungElement> element) const`: Method to check if connected to another rung element.

## File: wire.h

### Methods:

- `std::shared_ptr<RungElement> getStartElement() const`: Returns the start element of the wire.
- `std::shared_ptr<RungElement> getEndElement() const`: Returns the end element of the wire.

## File: rung_submodule.h

### Methods:

- `void addElement(std::shared_ptr<RungElement> element)`: Adds a RungElement to the submodule.
- `bool evaluate(std::unordered_map<std::string, bool>& states)`: Evaluates the submodule based on the current states.
- `std::vector<std::shared_ptr<RungElement>>& getElements()`: Returns the elements of the submodule.

## File: ladder_parser.h

### Methods:

- `static std::unordered_map<std::string, bool> parseLadderFile(const std::string& filename)`: Parses a ladder logic file and returns the elements with their initial states.

## File: logic_element.h

### Methods:

- `bool evaluate(std::unordered_map<std::string, bool>& states) override`: Overrides the virtual method to evaluate the logical element.

## File: output_element.h

### Methods:

- `bool evaluate(std::unordered_map<std::string, bool>& states) override`: Overrides the virtual method to evaluate the output element.
- `std::string getName()`: Returns the name of the output element.
- `bool getState()`: Returns the state of the output element.

## File: timer_element.h

### Methods:

- `bool evaluate(std::unordered_map<std::string, bool>& states) override`: Overrides the virtual method to evaluate the timer element.
- `void reset()`: Resets the timer element to its initial state.

## File: pushbutton.h

### Methods:

- `bool evaluate(std::unordered_map<std::string, bool>& states) override`: Overrides the virtual method to evaluate the push button element.
- `std::string getName() const override`: Returns the name of the push button element.
- `void setState(bool state)`: Sets the state of the push button element.

## File: contact.h

### Methods:

- `bool evaluate(std::unordered_map<std::string, bool>& states) override`: Overrides the virtual method to evaluate the contact element.
- `std::string getName() const override`: Returns the name of the contact element.

## File: coil.h

### Methods:

- `bool evaluate(std::unordered_map<std::string, bool>& states) override`: Overrides the virtual method to evaluate the coil element.
- `std::string getName() const override`: Returns the name of the coil element.

## File: bulb.h

### Methods:

- `bool evaluate(std::unordered_map<std::string, bool>& states) override`: Overrides the virtual method to evaluate the bulb element.
- `std::string getName() const override`: Returns the name of the bulb element.
- `bool isTerminatingElement() const override`: Returns true if the bulb is a terminating element.

## File: simulator.h

### Methods:

- `void setInput(const std::string& name, bool state)`: Sets the input state for the simulator.
- `bool getOutput(const std::string& name)`: Returns the output state from the simulator.
- `void addRung(Rung rung)`: Adds a rung to the simulator.
- `void simulate()`: Simulates the ladder logic program.
- `std::unordered_map<std::string, bool> getOutputStates() const`: Returns the output states from the simulator.



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


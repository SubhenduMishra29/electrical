# Project Documentation

## 1. `Bus` Class

### Header File (`Bus.h`)
- **Attributes:**
  - `std::string id` - Bus ID
  - `Voltage voltage` - Voltage at the bus
  - `Current totalCurrent` - Total current flowing through the bus
  - `std::vector<std::string> lineIds` - List of line IDs connected to the bus

- **Methods:**
  - **Constructor:**
    - `Bus()` - Default constructor
    - `Bus(const std::string& id, const std::string& voltageStr)` - Constructor with parameters
  - **Member Functions:**
    - `void addLine(const std::string& lineId)` - Adds a line ID to the bus
    - `void updateBusValues(const std::unordered_map<std::string, std::shared_ptr<Line>>& lineMap)` - Updates the bus’s total current based on connected lines
    - `void displayInfo(const std::unordered_map<std::string, std::shared_ptr<Line>>& lineMap) const` - Displays bus information and connected lines

## 2. `Line` Class

### Header File (`Line.h`)
- **Attributes:**
  - `std::string id` - Line ID
  - `Current inCurrent` - Incoming current
  - `Current outCurrent` - Outgoing current
  - `double impedance` - Impedance of the line
  - `double capacitance` - Capacitance of the line
  - `double inductance` - Inductance of the line

- **Methods:**
  - **Constructor:**
    - `Line()` - Default constructor
    - `Line(const std::string& id, double impedance, double capacitance, double inductance)` - Constructor with parameters
  - **Member Functions:**
    - `Current getOutCurrent() const` - Gets the outgoing current
    - `void setOutCurrent(const Current& current)` - Sets the outgoing current
    - `Current getInCurrent() const` - Gets the incoming current
    - `void setInCurrent(const Current& current)` - Sets the incoming current
    - `void update()` - Updates the line properties (implementation needed)
    - `void displayInfo() const` - Displays line information

## 3. `Current` Class

### Header File (`Current.h`)
- **Attributes:**
  - (Assumed attributes related to current magnitude and phase)

- **Methods:**
  - **Constructors:**
    - Constructors to initialize current (assumed based on context)
  - **Member Functions:**
    - `void printDetails() const` - Prints the details of the current object
    - Overloaded operators for arithmetic operations (assumed based on usage)

## 4. `Voltage` Class

### Header File (`Voltage.h`)
- **Attributes:**
  - (Assumed attributes related to voltage magnitude and phase)

- **Methods:**
  - **Constructors:**
    - Constructors to initialize voltage (assumed based on context)
  - **Member Functions:**
    - `void setReal(double real)` - Sets the real part of the voltage
    - `void setImaginary(double imaginary)` - Sets the imaginary part of the voltage
    - `void printDetails() const` - Prints the details of the voltage object

## 5. Utility Functions

### Header File (`parser_utils.h`)
- **Functions:**
  - `SplitResult splitNumberAndChars(const std::string& str)` - Splits a string into number and character parts

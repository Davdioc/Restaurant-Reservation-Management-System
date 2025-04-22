# Restaurant-Reservation-Management-System

A simple console-based Restaurant Reservation Management System implemented in C++. This system allows users to manage tables, make reservations, and display scheduled bookings. It follows an object-oriented design, using classes to represent core entities such as `Restaurant`, `Table`, `Reservation`, `Date`, and `Time`.

---

## Features

- Add and manage restaurant tables
- Make reservations based on date, time, and capacity
- Prevent overlapping reservations
- Display all reservations
- Input/output handled via a clean CLI (command-line interface)

---

## File Structure

| File               | Description |
|--------------------|-------------|
| `main.cc`          | Entry point of the program; invokes `Control::launch()` |
| `Control.h/cc`     | Core controller managing the restaurant and view interaction |
| `Restaurant.h/cc`  | Manages tables and reservation bookings |
| `Table.h/cc`       | Represents individual tables with number and capacity |
| `Reservation.h/cc` | Handles reservation logic, links patrons to tables on specific date/time |
| `Date.h/cc`        | Manages date validation, comparison, and formatting |
| `Time.h/cc`        | Handles time values, comparisons, and overlaps |
| `RsvList.h/cc`     | Linked list to manage reservations internally |
| `View.h/cc`        | Command-line user interface for interaction |
| `defs.h`           | Contains global constants (e.g., hours, max array size) |
| `Makefile`         | Compiles all `.cc` files into an executable |
| `README.md`        | Project documentation (this file) |

---

## How to Compile

Run the following command in your terminal:

```bash
make

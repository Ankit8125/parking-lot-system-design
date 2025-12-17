# 🅿️ Parking Lot Management System (CPP)

## 📝 Project Overview

This project aims to implement a comprehensive **Parking Lot Management System** focusing on core business logic. The system is designed to manage a multi-floor parking facility, supporting **smart vehicle assignment**, real-time **occupancy tracking**, and flexible search operations.

## 🎯 Task

Implement the core business logic for the Parking Lot Management System to handle different vehicle types efficiently, optimize space utilization, and adhere to specific business rules.

## 🏗️ Core Entities and Attributes

| Entity | Description |
| :--- | :--- |
| **Vehicle** | Represents a vehicle with a license plate, type, and owner information. |
| **ParkingSpot** | Represents a parking spot with an ID, type, floor number, and current status. |
| **ParkingTicket** | Generated when a vehicle is parked; contains entry/exit timestamps. |

### Enumerations

* **VehicleType:** `MOTORCYCLE`, `CAR`, `TRUCK`
* **SpotType:** `COMPACT`, `REGULAR`, `LARGE`
* **SpotStatus:** `AVAILABLE`, `OCCUPIED`, `RESERVED`

## ⚙️ Functionalities to Implement

| Method | Description |
| :--- | :--- |
| `add_parking_spot` | Add a new parking spot to the system. |
| `remove_parking_spot` | Remove a parking spot from the system. |
| `park_vehicle` | Park a vehicle and generate a parking ticket. |
| `exit_vehicle` | Process vehicle exit, calculating duration/fee (implied). |
| `find_vehicle_by_license` | Find the current location (spot) where a vehicle is parked. |
| `get_available_spots_by_type` | Get available spots of a specific type. |
| `get_parking_spot` | Get a parking spot by its ID. |

## 📜 Business Rules

### 1. Spot Management

* Each spot must have a **unique ID** (duplicates are not allowed).
* Invalid inputs should be handled gracefully (e.g., return `False` or `None`).

### 2. Vehicle Parking

* When a vehicle parks, the spot status changes to **OCCUPIED**, and the vehicle's license plate is recorded.
* A **ParkingTicket** is generated with the **entry timestamp**.

### 3. Smart Spot Assignment

Not all vehicles can park in all spots. Compatibility must be enforced:

| Vehicle Type | Can Park In (Spot Type) |
| :--- | :--- |
| **MOTORCYCLE** | `COMPACT`, `REGULAR`, `LARGE` |
| **CAR** | `REGULAR`, `LARGE` |
| **TRUCK** | `LARGE` only |

The system must also optimize space utilization:

* **Prefer smaller compatible spots:** Do not assign a `LARGE` spot to a motorcycle if a `COMPACT` spot is available.
* **Prefer lower floors:** When multiple equivalent spots exist, choose the one on the lower floor.

### 4. Vehicle Exit

* When a vehicle exits, the spot status becomes **AVAILABLE** again.
* The vehicle should no longer be findable in the system's active records.

## ✅ Expectations

* Identify any **remaining entities and attributes** required for the specified functionality.
* **No UI or REST APIs** are required; focus is solely on the core business logic.
* Employ **coding best practices** (SOLID, DRY, etc.) to ensure modularity and extensibility.
* **No external database** is permitted. Use suitable **in-memory data structures** (lists, maps, dictionaries, etc.) for storage.
* Functionality must be verified using **unit test cases**.
* The primary focus is on the **implementation of core functionality**.
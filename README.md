# Arbitrary Precision Calculator

A C library for performing arithmetic operations on numbers of unlimited size, overcoming the limitations of standard integer data types.

## Overview

This project implements a calculator capable of handling arbitrary precision arithmetic. Using a custom linked list data structure, the calculator can work with numbers of virtually any length, making it useful for applications requiring high precision calculations.

## Features

- Handles addition, subtraction, multiplication, and division
- Works with integers of any size (limited only by available memory)
- Supports negative numbers
- Memory-efficient implementation using doubly linked lists

## How It Works

The calculator represents numbers as linked lists of digits, where each node in the list contains a single digit. This approach allows for:

- Dynamic memory allocation based on the actual size of the numbers
- Efficient digit-by-digit operations
- Seamless handling of carrying, borrowing, and other arithmetic necessities

## Input & Output

**Input format:** Numbers are supplied as strings, allowing for input of any length.

**Output format:** Results are displayed as properly formatted numbers, with appropriate sign indicators and no unnecessary leading zeros.

## Basic Operations

- **Addition**: Combines two numbers to produce their sum
- **Subtraction**: Finds the difference between two numbers, handling cases where the result may be negative
- **Multiplication**: Produces the product of two numbers using optimized algorithms
- **Division**: Divides one number by another, providing the quotient

## Project Structure

The project is organized into several modules:

- **Types**: Defines the core data structures (OPERAND and NODE)
- **Operations**: Contains utility functions for number manipulation
- **Arithmetic modules**: Separate modules for addition, subtraction, multiplication, and division


## Future Enhancements

- Support for floating-point operations
- Additional mathematical functions (exponentiation, square root, etc.)
- Performance optimizations for large-scale calculations


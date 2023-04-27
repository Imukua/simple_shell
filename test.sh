#!/bin/bash

# Test 1: Shell displays prompt and waits for user input
echo "Test 1: Display prompt and wait for user input"
output=$(echo -e " \n" | ./shipshell)
expected_output="$ "
if [ "$output" != "$expected_output" ]; then
    echo "Test 1 failed: expected '$expected_output', but got '$output'"
else
    echo "Test 1 passed"
fi

# Test 2: Shell displays prompt again after command is executed
echo "Test 2: Display prompt again after command is executed"
output=$(echo -e "echo hello\nexit\n" | ./shipshell)
expected_output="$ hello\n$ "
if [ "$output" != "$expected_output" ]; then
    echo "Test 2 failed: expected '$expected_output', but got '$output'"
else
    echo "Test 2 passed"
fi

# Test 3: Shell handles one-word command lines only
echo "Test 3: Handle one-word command lines only"
output=$(echo -e "ls -la\nexit\n" | ./shipshell)
expected_output="Command not found\n$ "
if [ "$output" != "$expected_output" ]; then
    echo "Test 3 failed: expected '$expected_output', but got '$output'"
else
    echo "Test 3 passed"
fi

# Test 4: Shell displays error message if executable not found
echo "Test 4: Display error message if executable not found"
output=$(echo -e "not_a_valid_command\nexit\n" | ./shipshell)
expected_output="Command not found\n$ "
if [ "$output" != "$expected_output" ]; then
    echo "Test 4 failed: expected '$expected_output', but got '$output'"
else
   echo "Test 4 passed"
fi
#Test 5: Shell handles end of file condition (Ctrl+D)

echo "Test 5: Handle end of file condition (Ctrl+D)"
output=$(echo -e "echo hello\n" | ./shipshell)
expected_output="Command not found\n$ "
if [ "$output" != "$expected_output" ]; then
echo "Test 5 failed: expected '$expected_output', but got '$output'"
else
echo "Test 5 passed"
fi
#Test 6: Shell handles errors

echo "Test 6: Handle errors"
output=$(echo -e "invalid_command\nexit\n" | ./shipshell 2>&1)
expected_output="shipshell: invalid_command: command not found\n$ "
if [ "$output" != "$expected_output" ]; then
echo "Test 6 failed: expected '$expected_output', but got '$output'"
else
echo "Test 6 passed"
fi
#End of test suite

echo "End of test suite"
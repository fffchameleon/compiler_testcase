# compiler_testcase

in hw1 create testcase file
```
mkdir testcase
cd testcase
git clone https://github.com/fffchameleon/compiler_testcase.git
```
in hw1, create script
```
vim ./run_test.sh 
```
```bash
#!/bin/bash

TEST_DIR="testcase"
EXECUTABLE="scanner"

for test_file in ${TEST_DIR}/*; do
    echo "Running test: ${test_file}"
    ./${EXECUTABLE} < "${test_file}" > "${EXECUTABLE}_output"
    golden_scanner < "${test_file}" > "golden_output"
    diff "${EXECUTABLE}_output" golden_output
    echo "--------------------------------------"
done
```
```
chmod +x ./run_test.sh
```

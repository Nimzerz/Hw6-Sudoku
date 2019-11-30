## Write the sudoku solver (50pt)

Use folder ```sudoku```.

### 1. (30pt) Complete the sudoku solver in src/sudoku.h 

```c++
bool solve() {
     // homework
     return false;   // placeholder
}
```

This will solve the sudoku problem set in 
```c++
private:
    int grid[9][9]{};
```

Please use recursion(backtracking) to solve this problem. OK to apply any optimization. See [this](https://attractivechaos.wordpress.com/2011/06/19/an-incomplete-review-of-sudoku-solver-implementations) for possible ideas of optimization.

For your testing purpose, [this](https://sudokusolver.net) is a free online solver. In addition to the class materials, [here](https://hackernoon.com/sudoku-and-backtracking-6613d33229af) is a good resource exploring how to solve this problem. Plenty others available online. Please specify reference and credit if you end up using other's idea.

Tests are provided in test/unit_tests.cpp. Upon finishing the problem, these test cases should all PASS. 


### 2. (20pt) Complete the sudoku solver in src/sudoku.h 

Add at lease one test case of your own following the format of provided tests. 

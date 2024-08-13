To time the program call
```sh
make run ITERS=N
```
where N is the number of iterations you want it to run.

Currently this is running with the `-O1` flag. It achieves a 7x speedup over `O0` in my testing. The time plot is linear, so it is not reducing the time complexity, but I have no idea if it is performing loop unrolling or other more aggressive techniques that sort of cheat out the purpose of th program. But that may not be the case.

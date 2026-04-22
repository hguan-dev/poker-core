# poker-core

A high-performance, low-latency C++ poker engine designed for discrete-event simulations and game theory research. This library serves as the foundational state machine for a **CFR (Counterfactual Regret Minimization)** Heads-Up No-Limit Hold'em solver.

## Overview
`poker-core` is engineered for speed and determinism. By stripping away non-essential overhead, the engine provides a bare-metal environment for iterating through game states at scale.

## Development & Performance
Performance is the primary metric for this project. Through iterative profiling and hot-path refactoring, game simulation latency has been significantly reduced:

* **Initial Runtime:** 119,687.5 ns (Avg. per simulation)
* **Current Runtime:** 33,126.38 ns (Avg. per simulation)
* **Performance Gain:** **72.31% reduction in latency**

## Technical Stack
* **Language:** C++ (Focus on cache-local data structures and SIMD-friendly logic)
* **Build System:** CMake
* **Package Management:** Conan
* **Toolchain:** GCC / GDB / `perf`

## Build Instructions
```bash
mkdir build && cd build
cmake ..
make
```

## Related Projects
* **[cfr-solver](https://github.com/hguan-dev/cfr-solver):** A Heads-Up No-Limit Hold'em solver utilizing Counterfactual Regret Minimization using similar latency reduction techniques (hand evaluator pulled directly from here)

This README is designed to highlight your technical decision-making and the sophisticated logic behind the **Dipole Algorithm**. It emphasizes the `sort_big` logic (the Branch and Bound approach) as the primary engine while showcasing the recursive 5-sort as a clean "Divide and Conquer" utility.

---

# How to install:

- download the code using git clone or any other recommended method
- you should have `make` installed; run make on the root
- change the permissions for the test files on the root or run the following command:

```
ARG=$(shuf -i 0-1000 -n 100); ./push_swap $ARG | wc -l
```

# possible _todos_ for those who dare to take this project even further

I left this projects as such. The dipole algo in particular was a continuation of an abandoned route before I decided to go for Radix to pass the project and stay on my pace, together the here presented algos for small sortings.

That means that particularly the dipole algo is still open to improvements:

- Some scripts and functions require further refactoring to comply with the Norm
- I went for updating nodes by swifting data instead of the nodes themselves (awful decision, I did it to prevent too many frees but it is not sounding for this project)
- There is still room for making the dipole algo even faster:
  - double moves are still not implemented
  - the final step of bringing the poles into a single sequence on A can have a small improvement

Extras that you might find positive:

- I do my best to keep a sounding architecture
- I do my best to keep a sounding code
- I do my best to keep a good tracking of leakings, implement error handling, etc
- My libft is in full too

# Description of the algos

## An option for the small Sort: Recursive State Reduction (N <= 5)

Instead of traditional hard-coded conditional blocks, this project uses a **Recursive Divide and Conquer** strategy for small datasets.

- **Recursive Step:** The algorithm identifies the extreme value, pushes it to Stack B, and calls itself for .
- **Base Case:** Once the stack is reduced to , it triggers an optimized 3-node permutation sort.
- **Backtracking:** As the recursion unfolds, the isolated values are pushed back into their perfectly sorted positions.

## The Dipole Algorithm (N > 5)

A high-performance sorting solution for the 42 Push_Swap project, achieving **5100 moves (average) for 500 elements** even without double-move optimization. Put it simple, it consists on trying to keep the sorted order of two opposing sequences ("poles") on the B stack after moving one element from A, and once all elements from A have been placed on one of the opposing sequences on B sort those two sequences back as one single sort into the A stack.

### 1. The Core Engine: Dipole Search

The algorithm treats Stack B as a "field" with two opposing sorted sequences that have orientation: one sequence has **positive** orientation, and the other one has **negative** orientation.

#### A. Branch and Bound Search

The process to get an element from A that should be placed on B is not random. It consists in finding and comparing the **candidates with the less amount of movements to be placed in one or another "pole"**. The selection process is not a simple linear scan. It employs **Branch and Bound pruning** to minimize calculation overhead:

- **Initial Bound:** The algorithm calculates the cost of the candidate at the `head` of Stack A to establish a "Distance Budget."
- **The Branching:** It then branches out, searching from both the **Top** and then the **Bottom** of Stack A.
- **The Pruning:** If the cost to simply reach a node (its distance from the head/tail) exceeds the current "Distance Budget," the algorithm **prunes** that branch and dischard those nodes that won't beat the current budget. As it is now for this version, the budget is only updated after exploring the elements of the **Top** branch. The new budget is then used to prune the candidates of the **Bottom** branch.

#### B. The Dipole (Perspective Shifting)

To solve the "tail-to-head" gap problem inherent in circular lists, the algorithm uses a **Precession/Parallax** trick:

- Before calculating costs, it performs a temporary `reverse_rotate` to shift the stack's orientation.
- This brings the "invisible" gap between the last and first nodes into the primary search loop.
- By shifting the perspective, the algorithm treats the circular wrap-around as a standard sequence, ensuring 100% accuracy in finding the optimal insertion point.

### 2. Performance Table based on valid moves

| Dataset Size     | Your Move Count (Est.) | 42 Project Limit (5/5) | Performance Grade     |
| ---------------- | ---------------------- | ---------------------- | --------------------- |
| **3 Elements**   | 2-3                    | 3                      | Perfect               |
| **5 Elements**   | 8-11                   | 12                     | Optimized (Recursive) |
| **100 Elements** | **580** average        | 700                    | Elite Tier            |
| **500 Elements** | **5100** average       | 5500                   | Elite Tier            |

#### Why this logic is faster than the "Average"

Most of the projects settle for a simple "Radix" sort (which is roughly 1084 moves for 100) or a "Chunk" sort (which is roughly 700-800 moves).

This **Dipole Algorithm** is also performance-faster because:

1. **Branch and Bound:** this is not checking all the elements but only the ones that actually have a chance to win.
2. **Circular Efficiency:** the project implement a "smart rotation" trick that finds instantly some of the positions and move only when necessary.

### 3. Key Technical Tools Used

- **Greedy Optimization:** The project uses simple rules, selecting the locally optimal move at each step.
- **Pseudo Binary**: By offering not one but two possible preliminary slots for some of the elements, the possibilities for finding a shortest path for some values gets duplicated.
- **Heuristic Pruning:** Using the `distance_budget` to skip sub-optimal nodes.
- **Circular Invariant Management:** Ensuring the stack remains a perfect circular sequence through every push.

### 4. Challenges

Challenges of the project are:

- Changing "polarities" - Making the right comparisons and then keeping the correct orientations of the elements when exploring and eventually placing elements between "poles" or "fields"
- Treating the limits - how to place local or global maxs or mins values for any of the existing poles and correctly assigning an orientation (maxs and mins, when found together, involve a change in "polarity")
- Circularity - this is specially difficult notion to grasp: calculating if an element should be placed as jammed between the head and the tail of B is not immediately trivial (this is well solved in this project by _problem simplication_)

---

```mermaid
%%{init: {'themeVariables': { 'fontSize': '10px' }}}%%
flowchart TD
    Start([Start Sort: Pile A full, Pile B empty]) --> ScanA[Identify A Candidates]

    %% Gate 1: Proximity
    ScanA --> Gate1{shorter path to top pile?}
    Gate1 -- Yes: update orienation --> SetTarget[dist and orientation]

    %% Gate 2: Break-even
    Gate1 -- No --> Gate2[look at the next pile] --> SetNewTarget[new dist and orientation]
    SetTarget --> SetSmallest
    SetNewTarget --> SetSmallest[compare both and select]
    SetSmallest --> Challenger[compare to current winner]
    Challenger --> Winner[select winner]
    Winner --> AllCompared{all candidates compared}
    AllCompared --> |no| ScanA
    %% Cost & Placement
    AllCompared --> |yes| CalcSeam[Calculate Placement in B]



    CalcSeam --> ZoneChoice{Which Cone fits better?}
    ZoneChoice -- Top Down --> ZoneTop[ZONE_TOP: Highest rank at Head]
    ZoneChoice -- Bottom Up --> ZoneBot[ZONE_BOTTOM: Highest rank at Tail]

    %% Execution
    ZoneTop --> Exec[Execute moves via univ_oper]
    ZoneBot --> Exec

    Exec --> EmptyA{Is Pile A empty?}
    EmptyA -- No --> ScanA

    %% Phase 2: Merge
    EmptyA -- Yes --> Phase2[Phase 2: Zipper Merge]
    Phase2 --> Comp[Compare B-Head vs B-Tail]
    Comp --> PushHigh[Push Higher Value to Pile A]
    PushHigh --> EmptyB{Is Pile B empty?}
    EmptyB -- No --> Phase2
    EmptyB -- Yes --> End([End: Pile A Sorted])

    style Start fill:#f9f,stroke:#333,stroke-width:2px
    style End fill:#f9f,stroke:#333,stroke-width:2px
    style Gate1 fill:#bbf,stroke:#333,stroke-width:2px
    style Gate2 fill:#fbb,stroke:#333,stroke-width:2px

```

---

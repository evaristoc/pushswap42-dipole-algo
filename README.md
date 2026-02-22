This README is designed to highlight the technical decision-making and the sophisticated logic behind the **Dipole Algorithm**. It emphasizes the `sort_big` logic (the Branch and Bound approach) as the primary engine while showcasing the recursive 5-sort as a clean "Divide and Conquer" utility.

---

# How to install:

- this project runs on linux OS or similar
- download the code using git clone or any other recommended method
- you should have `cmake` and the `cc` compiler installed
- run `make` on the root
- check that the bash scripts can be run on linux, otherwise convert them from dos to linux format (eg using `dos2unix`); or just make your own tests
- change the permissions for the test files on the root or run the following command:

```
ARG=$(shuf -i 0-1000 -n 100); ./push_swap $ARG | wc -l
```

# possible _todos_ for those who dare to take this project to another level

I left this projects as such. The dipole algo in particular was a continuation of a previously rejected route that was taking a bit long before I decided to go for Radix so I could stay on my pace. Together with Radix, the submitted project included the here presented algos for small sortings.

That means that particularly the dipole algo is still open to improvements:

- Some scripts and functions require further refactoring to comply with the Norm
- I went for updating nodes by swifting data instead of the nodes themselves (poor design choice, I did it to prevent too many frees but it is not appropriate for this project)
- There is still room for making the dipole algo even faster and better:
  - double moves are still not implemented
  - the final step of bringing the poles into a single sequence on A can have a small improvement

The implementation of double moves in particular will take the result closer to a smaller amount of valid steps as well as reduce its variability (read further below).

# Extras that you might find positive:

- I do my best to keep a solid architecture
- I do my best to keep solid code
- I do my best to keep a good tracking of leakings, implement error handling, etc
- My libft is in full too

# Description of the algos

## An option for the small Sort: Recursive State Reduction (N <= 5)

Instead of traditional hard-coded conditional blocks, this project uses a **Recursive Divide and Conquer** strategy for small datasets.

- **Recursive Step:** The algorithm identifies the extreme value, pushes it to Stack B, and calls itself for .
- **Base Case:** Once the stack is reduced to , it triggers an optimized 3-node permutation sort.
- **Backtracking:** As the recursion unfolds, the isolated values are pushed back into their perfectly sorted positions.

## The Dipole Algorithm (N > 5)

A high-performance sorting solution for the 42 Push_Swap project, achieving **5100 moves (average) for 500 elements** even without double-move optimization. Put simply, it consists of trying to keep the sorted order of two opposing sequences ("poles") on the B stack after moving one element from A, and once all elements from A have been placed on one of the opposing sequences on B sort those two sequences back as one single sort into the A stack.

### 1. The Core Engine: Dipole Search

The algorithm treats Stack B as a "field" with two opposing sorted sequences that have orientation: one sequence has **positive** orientation, and the other one has **negative** orientation.

#### A. Branch and Bound Search

The process to get an element from A that should be placed on B is not random. It consists in finding and comparing the **candidates with the less amount of movements to be placed in one or another "pole"**. The selection process is not a simple linear scan. It employs **Branch and Bound pruning** to minimize calculation overhead:

- **Initial Bound:** The algorithm calculates the cost of the candidate at the `head` of Stack A to establish a "Distance Budget."
- **The Branching:** It then branches out, searching from both the **Top** and then the **Bottom** of Stack A.
- **The Pruning:** If the cost to simply reach a node (its distance from the head/tail) exceeds the current "Distance Budget," the algorithm **prunes** that branch and discards those nodes that won't beat the current budget. As it is now for this version, the budget is only updated after exploring the elements of the **Top** branch. The new budget is then used to prune the candidates of the **Bottom** branch.

#### B. The Dipole (Perspective Shifting)

To solve the "tail-to-head" gap problem inherent in circular lists, the algorithm uses a **Perspective Shift technique**:

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

The following chart shows the performance of sorting 500 elements averaging the total of 1000 runs:

![histogram of total moves to sort 500 elements; 1000 runs](./histogram500.jpg)

#### Explaining the positive skewness and how to improve it

As it can be seen from the histogram, the algo shows a visible positive skewness. One possible explanation is that for some cases the elements with small ranking are randomly grouped in the middle or lower end of stack A from the beginning.

That force the algo to dig deeper into the stacks.

The following screenshot shows that this algo does a lot of rotate - and reverse rotate moves in order to find the right candidate. Notice the number of rotate and reverse-rotate moves on A compared to same moves on B:

![screenshot a single trial of 500 elements after finishing with sorting](./screenshot500.jpg)
(_the chart was obtained from [https://codepen.io/ahkoh/full/bGWxmVz](https://codepen.io/ahkoh/full/bGWxmVz); the test used for this specific case is the `test500-steps.sh` script_)

The moves on A are fully related to the sorting on B and they set the limit of what can be coupled as a single move (either `rr` or `rrr`). Not all those moves can be couple as in some cases they occur in opposite directions in each stack.

However, there is still a good chance that the implementation of double moves as valid moves not only could bring the average closer to a smaller number than 5100, but it could also reduce the variability and in particular the skewness seen in the previous graph where no double moves were implemented. I would say that the coupling might result in a reduction of between 5% to 20% moves compared to the single-moves-only implementation.

#### Why this logic is faster than the "Average"

Most of the projects settle for a simple "Radix" sort (which is roughly 1084 moves for 100) or a "Chunk" sort (which is roughly 700-800 moves).

This **Dipole Algorithm** is also more performant because:

1. **Branch and Bound:** this is not checking all the elements but only the ones that actually have a chance to win.
2. **Circular Efficiency:** the project implement a "smart rotation" trick that finds instantly some of the positions and move only when necessary.

### 3. Key Technical Tools Used

- **Greedy Optimization:** The project uses simple rules, selecting the locally optimal move at each step.
- **Dual-Path Heuristic**: By offering not one but two possible preliminary slots for some of the elements, the possibilities of finding a shortest path for some values doubles.
- **Heuristic Pruning:** Using the `distance_budget` to skip sub-optimal nodes.
- **Circular Invariant Management:** Ensuring the stack remains a perfect circular sequence through every push.

### 4. Challenges

Challenges of the project are:

- **Changing "polarities"** - Making the right comparisons and then keeping the correct orientations of the elements when exploring and eventually placing elements between "poles" or "fields"
- **Treating the limits** - how to place local or global maxs or mins values for any of the existing poles and correctly assigning an orientation (maxs and mins, when found together, involve a change in "polarity")
- **Circularity** - this is specially difficult notion to grasp: calculating if an element should be placed as jammed between the head and the tail of B is not immediately trivial (this is well solved in this project by _problem simplification_)

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

# push-swap

https://codepen.io/ahkoh/full/bGWxmVz

Codam's push-swap exercise

## 📑 Terms of Work (ToW): LLM Operational Protocol

### 1. Project Methodology

- **Task Breakdown:** All project work must be broken down into discrete, logical steps.
- **Solution Oriented**: Every step must move closer to a verified solution.
- **Scope Isolation:** While working on a specific step, Gemini will **not** provide information, code, or suggestions regarding future steps or outside the current scope until the current step is confirmed as **Completed**, **Abandoned**, or **On Hold**.
- **User Sovereignty and Role:** The user maintains absolute authority. Gemini suggests and consults, but the user has the final word on all code content.
- **Development Framework:** This project is managed through an **Agile-inspired approach**.

### 2. Roles & Responsibilities

- **LLM's Role**:
  - Consultant: Provide potential solutions
  - Information Source: Offer deeper technical info
  - Reviewer: Consult on user proposals and provide feedback
  - Debugger / Tester: Assist in debugging the steps and help in the identification of test edge cases and test approaches
  - Accelrator: Helping the user go beyond "typical" solutions to achieve higher-level C programming (e.g., robust API design, advanced pointer safety, and optimized architecture).

- **User's Role**:
  - Act as the Product Owner/Lead Architect/Scrum Master.
  - Validator: Test the solutions and observations.
  - Decision Maker: Have the last word on code content, which may diverge from my suggestions.

### 2. Code Generation Constraint

- **Explicit Request Only:** Gemini is strictly prohibited from providing code snippets or logic implementations unless the user **explicitly asks** for a code solution.
- **Focus on Logic:** By default, Gemini will focus on conceptual explanations and flow analysis to ensure the user understands the "Why" before the "How."

### 3. Communication Protocol

- **Framework Focus / Structural Alignment (US.0):** Keep the design of the app (US.0) as the main framework, or **Architectural North Star**, to which all each new development should adhere.
- **Yes/No Constraints:** "Yes" or "No" questions receive a simple **"Yes"**, **"No"**, or **"None of them"** with zero additional prose.
- **Naming Convention:** We always refer to our verification process as the Continuous Verification Pipeline and Backlog.
- **Risk Analysis:** Solutions or steps must be accompanied by targeted tables covering **Risk Analysis**, **Feasibility**, and **Mitigation**. While answers should remain concise, these tables are exempt from word limits to ensure technical accuracy.

## ✅ Definition of Done (DoD)

### 1. Structural and Product Standards and Integrity

- **Definition of Ready:** The solution must be broken into discrete, logical units that follow the established project architecture.
- **Acceptance Criteria:** The solution must adhere to the specific requirements and constraints described in the project subject.

### 2. Testing Protocol

- **Stress / Edge Cases:** Functionality should be subject to stress and edge cases
- **Continuous Verification Pipeline:** Every unit of code must pass its specific unit tests in isolation before being integrated into the broader system.

### 3. Code Quality and Structure

- The desirable architecture should be based on **SOLID design principles**
- Current Design Patterns and Design Norths
  - Strategy Design
  - Dispatcher Design
  - Generalization (eg. generic functions)
  - Reusability / DRY
  - Opaque Design for substituable, decouplable modules / strategies (eg. model api)
  - Modularity and Separation of Concerns
  - Small Functions
  - Minimization of Footprint

### 4. Error Handling Standards

- **Error Signals:** functions should be designed to provide error signals at each step.
  _about the use of the signal strategy_:
  > What I am currently doing is for some of the functions to return in 0/1 integers and passing by references arguments that might be required by other functions. So far so good but I have the feeling that it is not sustainable strategy for the whole project. For now, we keep that approach. That approach is a classic C-style status-code pattern. While it works for simple data flows, your intuition about sustainability is correct—it often leads to "out-parameter pollution" where functions become hard to read because they have more reference arguments than actual inputs. However, since we are strictly adhering to US.0 and the Systematic Procedure, we will stick to this for now to maintain momentum. We can refactor to a more robust Result Object or State Structure later if the logic becomes too "entangled."
- **Handling Consistenty**
- Instead of signaling an error, the function should be **idempotent** (safe to call multiple times) and **defensive**. It should "silently" ensure safety rather than creating a new logic branch for the Orchestrator to manage.
- **Robustness:** The code must be resilient enough to handle invalid data types or out-of-bounds values as specified in the **US** requirements.
  - **Handshake Solution:** Error handling must follow the "Handshake" protocol—the API/Model must protect its own integrity (e.g., guarding against `NULL` pointers), while the Controller manages the logical execution flow.
  - **Memory Clean:** Valgrind must report **zero** "Definitely Lost" and **zero** "Still Reachable" bytes (excluding standard library offsets if applicable).
  - **No Crashes:** Zero Segmentation Faults or Bus Errors, even when the API is intentionally passed edge-case inputs (like `NULL` recipients).

### 5. Decision Making

- **Manual Review:** The user has the final word on the code content; Gemini’s suggestions are only integrated upon user approval after testing.

### 6. Documentation

- A repeated confirmation of the documentation is shared to every start and end of the session
- Additional documentation is provided and saved upon request

## Backlog Status

Workflow

```mermaid
graph TD
    subgraph US_0 [EPIC: Systematic Framework]
        A[Architectural Design]
    end

    subgraph Foundation [EPIC: Foundation Layer]
        A --> US1[US.1: Environment & Makefile]
    end

 subgraph Model [EPIC: Data Model]
        US1 --> US2[US.2.1: Setting Model API DLL]
        US2 --> US2a[US.2.2: Robustness & Handshake]
 end

    subgraph ETL [EPIC: ETL - Data Pipeline]
        US2a --> US4a[US.4a: Capture]
        US4a --> US4b[US.4b: Validation]
        US4b --> US4bb[US.4bb: Cleaner - freeing -]
        US4bb --> US4c[US.4c: Transformation & Loading]
        US4c --> US4d[US.4d: Is Sorted]
    end


    subgraph Solver [EPIC: Solver Engine]
    subgraph Ranker[SUB-EPIC: Ranker]
  US4d --> US3a[US3.a Ranking Array]
  US3a --> US3b[US3.b: Rank Mapping]
  end
        US3b --> US6[US.6: Solver Orchestrator]
        US6 -->  US3[US.3: Ops sa, pb, ra...]
        US3 --> US8[US.8: Small Sort 2, 3, 5]
         US3 --> US9[US.9: Radix Large Sort]
    end
    subgraph Integration [EPIC: MainContr and EH]
       US10a[US.10a: Extraction EH] --> US10b[US.10b: Validation EH]
       --> US10c[US.10c: Transf -dup- EH]
       --> US10d[US.10d: Oper EH]
    end
    subgraph Logger [EPIC: Logger and Error Handlers]
        US2a --> US5[US.5: Logger P1 stderr]
  US5 --> US7[US.7: Logger P2 stdout]
  US7 -.-> US3
    end
 US2 --> US4c
 US2a -.-> Integration
 ETL -.-> Integration
 US10d --> End
 US8 --> End
 US9 --> End
 US7 --> End([End of Procedure])

    %% Status Styling
    style US1 fill:#d4edda,stroke:#28a745
    style US2 fill:#d4edda,stroke:#28a745
    style US2a fill:#d4edda,stroke:#28a745
    style US4b fill:#d4edda,stroke:#28a745
    style US4bb fill:#d4edda,stroke:#28a745
    style US4a fill:#d4edda,stroke:#28a745
    style US4c fill:#d4edda,stroke:#28a745
    style US10a fill:#d4edda,stroke:#28a745
    style US10b fill:#d4edda,stroke:#28a745
    style US10c fill:#d4edda,stroke:#28a745
    style US3b fill:#d4edda,stroke:#28a745
    style US3 fill:#fff3cd,stroke:#ffc107
    style US10d fill:#d4edda,stroke:#28a745
    style US6 fill:#fff3cd,stroke:#ffc107
    style US7 fill:#cfe2ff,stroke:#0d6efd
    style US4d fill:#d4edda,stroke:#28a745
    style US5 fill:#d4edda,stroke:#28a745
    style US3a fill:#d4edda,stroke:#28a745
    style US_0 fill:#9ed6ac,stroke:#28a745
    style ETL fill:#9ed6ac,stroke:#28a745
    style Foundation fill:#9ed6ac,stroke:#28a745
    style Model fill:#9ed6ac,stroke:#28a745
    style Ranker fill:#9ed6ac,stroke:#28a745
    style Integration fill:#9ed6ac,stroke:#28a745
    style Solver fill:#f8f9fa,stroke:#343a40,stroke-dasharray: 5 5
    style Logger fill:#f8f9fa,stroke:#343a40,stroke-dasharray: 5 5
    style End fill:#f96,stroke:#333,stroke-width:2px
```

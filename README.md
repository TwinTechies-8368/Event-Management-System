# 📘 Event Management System – Event Dependency DAG (CRUD in C)

---

## 📌 Project Title

**Event Management System using Directed Acyclic Graph (DAG)**

---

## 👥 Team Members

* Member 1: S.Pooja
* Member 2: S.Neha

---

## 🧩 Problem Statement

In real-world applications such as event planning, project workflows, and task scheduling, certain events depend on the completion of others. Managing these dependencies manually can lead to incorrect execution order or cyclic dependencies.

This project aims to:

* Represent events and dependencies efficiently
* Maintain a valid execution order
* Prevent cyclic dependencies
* Provide full CRUD operations for event management

---

## 🧠 Data Structure Used

* **Directed Acyclic Graph (DAG)**

  * Events → Nodes
  * Dependencies → Directed edges

* **Adjacency Matrix**

  * Stores relationships between events

* **Depth First Search (DFS)**

  * Used for cycle detection

---

## ⚙️ Algorithm Explanation

### ➤ 1. Create Event

1. Input event name
2. Assign a unique ID
3. Store event in array

---

### ➤ 2. Add Dependency

1. Input prerequisite event ID (A) and dependent event ID (B)
2. Add edge A → B in adjacency matrix
3. Run DFS to check for cycles
4. If cycle detected:

   * Remove edge
   * Display error message
5. Else: Confirm dependency

---

### ➤ 3. Cycle Detection (DFS)

1. Maintain two arrays:

   * `visited[]`
   * `recStack[]`
2. Traverse graph recursively
3. If a node is found in recursion stack → cycle exists

---

### ➤ 4. Display Events

1. Print all events with IDs
2. Traverse adjacency matrix
3. Print all dependencies

---

### ➤ 5. Update Event

1. Input event ID
2. Search event
3. Modify event name

---

### ➤ 6. Delete Event

1. Input event ID
2. Remove event from array
3. Shift remaining elements
4. Update adjacency matrix

---

## ▶️ Compilation Instructions

```bash
gcc event_dag.c -o event
./event
```

---

## 🧪 Sample Output
**🧪 Sample Output 1 – Basic Creation**


<img width="372" height="220" alt="image" src="https://github.com/user-attachments/assets/0a7bd793-af11-4f8e-87b3-21006c6eecb6" />

<img width="302" height="87" alt="image" src="https://github.com/user-attachments/assets/07c04e26-712f-49f0-b671-78b4bdbadd53" />

<img width="388" height="77" alt="image" src="https://github.com/user-attachments/assets/05640be3-d87c-4147-be8a-c3b42ed77771" />

<img width="357" height="80" alt="image" src="https://github.com/user-attachments/assets/57da0469-ad58-43bd-8102-72b032d12188" />


**🔗 Sample Output 2 – Adding Dependencies**

<img width="337" height="98" alt="image" src="https://github.com/user-attachments/assets/5d77eb55-edf2-49a1-8623-083bd71ba7cd" />

<img width="346" height="93" alt="image" src="https://github.com/user-attachments/assets/ea0199aa-ece1-49d1-b947-44ff3088c269" />


**👀 Sample Output 3 – Display Events & DAG**

<img width="458" height="250" alt="image" src="https://github.com/user-attachments/assets/3d9727f6-fa22-45cf-98d6-fab787fca742" />


**❌ Sample Output 4 – Cycle Detection**

<img width="385" height="106" alt="image" src="https://github.com/user-attachments/assets/60f6af49-8967-4854-8880-a9449c76a55c" />


**✏️ Sample Output 5 – Update Event**

<img width="300" height="105" alt="image" src="https://github.com/user-attachments/assets/bec2e2f8-f6a4-44a0-bef9-725e652b1600" />


**🗑️ Sample Output 6 – Delete Event**

<img width="292" height="80" alt="image" src="https://github.com/user-attachments/assets/cf614899-eed6-4c92-b826-8a70582df989" />


**📊 Sample Output 7 – Final Display**

<img width="360" height="203" alt="image" src="https://github.com/user-attachments/assets/c2117581-4d7e-4dcd-9f17-3728bed9148e" />


**🚪 Sample Output 8 – Exit**

<img width="363" height="211" alt="image" src="https://github.com/user-attachments/assets/b8190774-c952-4b3a-b789-cd29ac2c7c73" />

---

## 🎥 Demo Video Link


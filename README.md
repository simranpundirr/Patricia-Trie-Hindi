# Space-efficient Dictionary Storage using Patricia Trie for Hindi Language

## Overview
This project compares a **Standard Trie** and a **Patricia (Compressed) Trie**
for storing Hindi (Devanagari) words.  
The goal is to experimentally show that **Patricia Trie uses significantly less
memory while maintaining efficient search performance**.

---

## Problem Statement
Standard tries consume large memory when storing dictionaries of regional
languages due to long words and many common prefixes.  
This project demonstrates how a **Patricia Trie compresses such paths** and
reduces memory usage without affecting search correctness.

---

## Dataset
A small Hindi dictionary was created to validate trie behavior and compression.

Location: data/hindi_words.txt

The dataset contains words with:
- Common prefixes
- Prefix-as-word cases
- Branching points  

This allows Patricia Trie compression to be clearly observed.

---

## Project Structure

src/
├── trie.h
├── trie.cpp
├── patricia_trie.h
├── patricia_trie.cpp
└── main.cpp
data/
└── hindi_words.txt

---

## Methodology

1. Read Hindi words from `hindi_words.txt`
2. Insert all words into:
   - Standard Trie
   - Patricia Trie
3. Count number of nodes used by each structure
4. Compare space usage trends

This experiment is implemented in `src/main.cpp`.

---

## How to Run

From the `src` folder:
g++ main.cpp trie.cpp patricia_trie.cpp -o compare
./compare

---

## Output (Sample)
Total words inserted: 20
Standard Trie Nodes: 132
Patricia Trie Nodes: 48

*(Exact values depend on dataset)*

---

## Why Patricia Trie is Better

In a standard trie, every character creates a new node.  
In a Patricia Trie, long chains of single-child nodes are **compressed into a single edge**, greatly reducing memory usage.

This is especially beneficial for **regional languages like Hindi**, where words are long and share prefixes.

---

## Time Complexity

| Operation | Trie | Patricia Trie |
|---------|------|---------------|
| Insert  | O(L) | O(L) |
| Search  | O(L) | O(L) |
| Space   | High | Low (compressed) |

---

## Future Enhancements
- Larger Hindi dictionary
- Byte-level memory profiling
- Prefix search and auto-complete
- Support for multiple languages



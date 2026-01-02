# Space-efficient Dictionary Storage using Patricia Trie for Hindi Language

## Problem Statement
Standard tries consume large memory when storing large dictionaries of regional
languages due to long words and many common prefixes.  
This project studies and demonstrates how a **Patricia (compressed) trie**
reduces memory usage while preserving search efficiency.

---

## Scope
- **Language:** Hindi (Devanagari)
- **Structures Compared:** Standard Trie vs Patricia Trie
- **Metrics:** Node count, memory usage trend
- **Focus:** Space efficiency

---

## Objectives
- To study the limitations of standard trie structures in storing large regional
  language dictionaries.
- To design and implement a Patricia trie for the same dataset.
- To compare space usage between standard trie and Patricia trie.
- To experimentally demonstrate that the Patricia trie is more space-efficient
  while maintaining search performance.

---

## Assumptions
- Words are pre-cleaned and valid.
- Case sensitivity is not applicable.
- Characters are treated as logical symbols, not raw bytes.

---

## Constraints
- Memory efficiency is prioritized over constant-time optimizations.
- Only prefix-based operations are considered.
- One regional language is used for the experiment.

---

## Evaluation Metrics
- Number of nodes created
- Average branching factor
- Total stored characters
- Memory usage trend (approximate)
- Correctness of search results

---

## Methodology
1. Collect a dictionary of Hindi words.
2. Construct a standard trie using the dataset.
3. Measure space-related metrics.
4. Construct a Patricia trie using the same dataset.
5. Measure the same metrics.
6. Compare results and analyze space efficiency.

---

## Expected Outcomes
- Patricia trie will use significantly fewer nodes than a standard trie.
- Memory consumption will reduce due to path compression.
- Search time complexity will remain **O(L)** for both structures.

---

## Limitations
- Memory usage is estimated, not measured at byte level.
- Unicode handling is simplified.
- Results may vary with different languages or datasets.

---

## Future Enhancements
- Extend support to multiple regional languages.
- Perform byte-level memory profiling.
- Add prefix-based search features.
- Compare with other compressed trie variants.

---

## Micro Dataset (Validation Set)
A small dictionary of Hindi words was created to validate trie and Patricia trie
structures. The dataset was designed to include common prefixes, branching points,
and prefix-as-word cases to clearly demonstrate path compression.

**Chosen Set of Words (Hindi – Devanagari):**
- राम
- रामायण
- रामकथा
- राज
- राजा
- राज्य
- रानी
- राष्ट्र


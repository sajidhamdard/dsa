$$
((a \% \text{MOD}) \times (b \% \text{MOD})) \% \text{MOD}
$$

It ensures **safe multiplication under modulo** and avoids **integer overflow**.

---

### ✅ Why do we need modulo at each step?

If you directly do:

$$
(a \times b) \% \text{MOD}
$$

It might **overflow** even before `\% MOD` is applied — especially if `a` and `b` are large (e.g., $10^9$).

---

### 🧠 Let's Understand Step-by-Step:

#### Step 1:

$$
a \% \text{MOD}
$$

→ Reduces `a` to a safe value under MOD.

#### Step 2:

$$
b \% \text{MOD}
$$

→ Same for `b`.

#### Step 3:

$$
(a \% \text{MOD}) \times (b \% \text{MOD})
$$

→ Now multiply two smaller numbers — less risk of overflow.

#### Step 4:

$$
\% \text{MOD}
$$

→ Apply modulo again to bring the final result under MOD.

---

### ✅ Modulo Multiplication Property:

$$
(a \times b) \% m = ((a \% m) \times (b \% m)) \% m
$$

This is a **mathematical identity** — and it's very useful in:

* Competitive programming
* Cryptography
* DSA problems involving large numbers

---

### 🔍 Example:

Let’s say:

* `a = 1\_000\_000\_006`
* `b = 2`
* `MOD = 1\_000\_000\_007` (a prime number)

Now:

* $a \% \text{MOD} = 1\,000\,000\,006$
* $b \% \text{MOD} = 2$

Then:

$$
((1\,000\,000\,006) \times 2) \% 1\,000\,000\,007 = 2\,000\,000\,012 \% 1\,000\,000\,007 = 1\,000\,000\,005
$$

Safe and correct. ✅

---

Let me know if you'd like to go deeper into modular arithmetic tricks like:

* Modular inverse
* Modular exponentiation
* Modular division

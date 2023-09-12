# Theorem: 
Suppose a function $f$ satisfies the following properties:

1. $f$ is a real continuous function on $\mathbb{R}$.
2. $f(\alpha)$ is the unique local minimum of $f$ on $X$.
3. $f$ is twice differentiable on $X$.
4. $\nabla^2 f(\alpha) ≠ 0$.

Then there exists $ε>0$ such that $f$ is convex on $S = [x : | x - \alpha | \leq ε]$ ...(1)

## Proof: 

Due to the definition of the second derivative, we can express $\nabla^2 f(\alpha) = \lim_{h \to 0} \frac {f(\alpha + h) + f(\alpha - h) - 2f(\alpha)}{h^2}$ (Due to 3), $∇^2 f(\alpha)$ exists.)

Property 2) $<=>$ for all $x \in X, f(\alpha) < f(x)$. Thus, $\nabla^2 f(\alpha) = \lim_{h \to 0} \frac {f(\alpha + h) + f(\alpha - h) - 2f(\alpha)}{h^2} \geq 0$.

Now, we aim to prove that near $\alpha$, $\nabla^2 f(x) \geq 0$.

### To prove this by contradiction, assume the following statement is true:

For all $ε>0$, there exist $x \in S = [x: 0< \| x - \alpha \| \leq ε] \text{ such that } f(x)$ is non-convex. ...(3)
### This statement is false because:

First, we fix $ε>0$, and let choose $ε_0 = inf[\|x-\alpha\| : x \in S \text{ and } ∇^2f(x)<0]$.

#### Case 1) $ε_0 ≠ 0$

Then (3) is a contradiction for $ε = ε_0$ (Because $S$ is bounded below, there exists an infimum.). Therefore, we see that when $ε_0 = 0$.
#### Case 2) $ε_0 = 0$
Then $ε_0$ is limit point of $T = [\|x-\alpha\| : x \in S \text{ and } ∇^2f(x)<0]$.

Thus there exists a sequence $\{x_n\}$ in $T' = [x : x \in S \text{ and } ∇^2f(x)<0]$ that converges to $\alpha$.

Then,
$∇^2 f(\alpha) = lim_{h → 0} \frac {f(\alpha + h) + f(\alpha - h)-2f(\alpha)}{h^2}$

$<=>$ For all $ε>0$ there exist $\delta>0$ such that
$\|h\|<\delta => \|∇^2 f(\alpha) -\frac {f(\alpha + h) + f(\alpha - h)-2f(\alpha)}{h^2}\| < ε$. ...(4)

From $x_n \to \alpha$,
Choose $\delta$ such that (4) then
there exist $N \in \text{N}$ such that $n \geq N => \|x_n - \alpha \| < \delta$. ...(5)

By (4) and (5), consequently
For all $ε>0$ there exist $N \in \mathbb{N}$ such that
$n \geq N => \|∇^2 f(\alpha) -\frac {f(x_n) + f(2\alpha - x_n)-2f(\alpha)}{(x_n - \alpha)^2}\| < ε$. ...(6)

By assumption 4),$∇^2 f(\alpha) >0$, (6) is false when $ε = ∇^2 f(\alpha)$. Therefore, (6) is false.

Thus, Negation of (1) is false. Consequently, (1) is True.

Proof end. □

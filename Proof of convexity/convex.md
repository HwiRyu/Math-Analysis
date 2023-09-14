# Theorem: 
Suppose a function $f$ satisfies the following properties:

1. $f$ is a real continuous function on $\mathbb{R}$.
2. $f(\alpha)$ is the unique local minimum of $f$ on $X$.
3. $f$ is twice differentiable on $X$ and $∇^2f(x)$ continuous on $X$.

Then there exists $ε>0$ such that $f$ is convex on $S = [x : | x - \alpha | \leq ε]$ ...(1)

## Proof: 

By Definition of the second derivative, we can express $\nabla^2 f(\alpha) = \lim_{h \to 0} \frac {\nabla f(\alpha + h) - \nabla f(\alpha)}{h}$ (Due to 3), $∇^2 f(\alpha)$ exists.)
Due to $\nabla f$ is monotone increasing near $\alpha$, $\nabla^2 f(\alpha) \geq 0$.

Now, we aim to prove that near $\alpha$, $\nabla^2 f(x) \geq 0$.

### To prove this by contradiction, assume the following statement is true:

For all $ε>0$, there exist $x \in S = [x: 0< \| x - \alpha \| \leq ε] \text{ such that } f(x)$ is non-convex. ...(3)
### This statement is false because:

First, we fix $ε>0$, and let choose $ε_0 = inf[\|x-\alpha\| : x \in S \text{ and } ∇^2f(x)<0]$.

#### Case 1) $ε_0 ≠ 0$
Then (3) is a contradiction for $ε = ε_0$ (Because $S$ is bounded below, there exists an infimum.). Therefore, we see that when $ε_0 = 0$.

Then $ε_0$ is limit point of $T = [\|x-\alpha\| : x \in S \text{ and } ∇^2f(x)<0]$.

## Case 2,3)

Due to $ε_0$ is limit point of $T$, 

There exists a sequence $\{x_n\}$ in $T' = [x : x \in S \text{ and } ∇^2f(x)<0]$ that converges to $\alpha$.

If there exist $ε$ such that $S-T' = \emptyset$, then $\int_{\alpha - ε}^{\alpha + ε}∇^2 f(x) = \int_{T'}∇^2 f(x) < 0$.
this is contradiction with near $\alpha, ∇ f(x)$ is monotone-increasing.
Therefore,  for all $ε$, $S-T' ≠ \emptyset$.
#### Case 2) $ε_0 = 0$ and  $\nabla^2 f(\alpha)>0$

Due to $\nabla^2 f(x)$ is continuous at $\alpha$
$<=>$ For all $ε>0$ there exist $\delta>0$ such that
$\|x-\alpha\|<\delta => \|∇^2 f(\alpha) -∇^2f(x)\| < ε$. ...(4)

From $x_n \to \alpha$,
Choose $\delta$ such that (4) then
there exist $N \in \text{N}$ such that $n \geq N => \|x_n - \alpha \| < \delta$. ...(5)

By (4) and (5), consequently
For all $ε>0$ there exist $N \in \mathbb{N}$ such that
$n \geq N => \|∇^2 f(\alpha) -∇^2f(x_n)\| < ε$. ...(6)

By assumption $∇^2 f(\alpha) >0$, (6) is false when $ε = ∇^2 f(\alpha)>0$(Because for all n, $∇^2f(x_n) < 0$). Therefore, (6) is false.

#### Case 3) $ε_0 = 0$ and  $\nabla^2 f(\alpha)=0$

Due to $\nabla^2 f(x)$ is continuous in $X$, for all $n \in {N},  \nabla^2 f(x)$ is continuous at $x_n$.

Therefore, for all $ε>0$ there exist $\delta>0$ such that
$\|x_n-x\|<\delta => \|∇^2 f(x_n) -∇^2f(x)\| < ε$, for all n. ...(7)

If $x$ satisfies $\|x_n-x\|<\delta$ and $x \in S-T' = [x : ∇^2 f(x) \geq0,0<\|x-\alpha\| \leq ε] ,$ Then (7) is false when $ε =- ∇^2 f(x_n) > 0$.

Therefore, (3) is false.
## Conclusion

Negation of (1) is false. Consequently, (1) is True.

Proof end. □


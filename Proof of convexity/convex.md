# Theorem of sophomore: 
Suppose function $f$ satisfies following property:
1) $f$ is real continuous function on $R$.
2) $f(\alpha)$ is unique local minimum of $f$ on $X$. 
3) $f$ is twice differentiable on $X$.

Then there exist $ε>0$ such that $f$ is convex on $S$ = $[x:\| x - \alpha \| \leq ε]$ ...(1)

## Proof: 

First, $∇ f(\alpha) = lim_{h → 0} \frac {f(\alpha + h)-f(\alpha)}{h} = 0$.
(Because if $h<0, \frac {f(\alpha + h)-f(\alpha)}{h} <0$ by 2), if $h>0, \frac {f(\alpha + h)-f(\alpha)}{h}>0$ and by 2), due to $f$ is differentiable on $X$.) ...(2)

Second, Due to definition of second derivative, we can express
$∇^2 f(\alpha) = lim_{h → 0} \frac {f(\alpha + h) + f(\alpha - h)-2f(\alpha)}{h^2}$ (Due to 3), $∇^2 f(\alpha)$ exist.)

2) $<=>$ for all $x \in X, f(\alpha) < f(x)$. Thus
$∇^2 f(\alpha) = lim_{h → 0} \frac {f(\alpha + h) + f(\alpha - h)-2f(\alpha)}{h^2} \geq 0$.

Now, ETS that near $\alpha$, $∇^2 f(x) \geq 0$ .

To prove this by contradiction, Assume following statement is True:

For all $ε>0$, there exist $x \in S = [x: 0< \| x - \alpha \| \leq ε] \text{ such that } f(x)$ is non-convex. ...(3)

This statement is false because:

First, we fix $ε>0$, and let choose $ε_0 = inf[\|x-\alpha\| : x \in S \text{ and } ∇^2f(x)<0]$.

if $ε_0 ≠ 0$, then (3) is contradiction in $ε = ε_0$. Therefore, we see when $ε_0 = 0$.

if $ε_0 = 0$ and $∇^2 f(\alpha) > 0$, then $ε_0$ is limit point of $T = [\|x-\alpha\| : x \in S \text{ and } ∇^2f(x)<0]$.

Thus there exists sequence $\{x_n\}$ in $T' = [x : x \in S \text{ and } ∇^2f(x)<0]$ that converges to $\alpha$.

Then,
$∇^2 f(\alpha) = lim_{h → 0} \frac {f(\alpha + h) + f(\alpha - h)-2f(\alpha)}{h^2}$

$<=>$ For all $ε>0$ there exist $\delta>0$ such that
$\|h\|<\delta => \|∇^2 f(\alpha) -\frac {f(\alpha + h) + f(\alpha - h)-2f(\alpha)}{h^2}\| < ε$. ...(4)

Due to $x_n \to \alpha$,
Choose $\delta$ s.t (4), then
there exist $N \in \text{N}$ such that $n \geq N => \|x_n - \alpha \| < \delta$. ...(5)

By (4) and (5), consequently
For all $ε>0$ there exist $N \in \text{N}$ such that
$n \geq N => \|∇^2 f(\alpha) -\frac {f(x_n) + f(2\alpha - x_n)-2f(\alpha)}{(x_n - \alpha)^2}\| < ε$. ...(6)

Due to $∇^2 f(\alpha) >0$ in this case, (6) is false when $ε = ∇^2 f(\alpha)$, thus (6) is false.

if $ε_0 = 0$ and $∇^2 f(\alpha) = 0$, then $ε_0$ is limit point of $\{\|x-\alpha\| : x \in S\}$, whatever.

Due to $∇^2 f(\alpha) = 0$ and  $f(\alpha$) is local minimum,
there exist $ε_2>0$ such that $\int_\alpha^{\alpha + ε_2} ∇^2 f(\alpha) > 0, \int_\alpha^{\alpha - ε_2} ∇^2 f(\alpha) > 0$.

Therefore, there exist $ε_3>0$ such that $∇^2 f(\alpha) \geq 0$, this is contradiction with (3).

Thus, Negation of (1) is false. Consequently, (1) is True.

Proof end. □

## 증명: 

먼저 당연히, $∇ f(\alpha) = lim_{h → 0} \frac {f(\alpha + h)-f(\alpha)}{h} = 0$.
(Because if $h<0, \frac {f(\alpha + h)-f(\alpha)}{h} <0$ by 2), if $h>0, \frac {f(\alpha + h)-f(\alpha)}{h}>0$ and by 2), due to $f$ is differentiable on $X$.) ...(2)

그 다음, definition of second derivative, $\alpha$에서의 헤시안을
$∇^2 f(\alpha) = lim_{h → 0} \frac {f(\alpha + h) + f(\alpha - h)-2f(\alpha)}{h^2}$ (Due to 3), $∇^2 f(\alpha)$ exist.)

2) $<=>$ for all $x \in X, f(\alpha) < f(x)$. ($x=\alpha$일때를 제외하고는)
따라서 $∇^2 f(\alpha) = lim_{h → 0} \frac {f(\alpha + h) + f(\alpha - h)-2f(\alpha)}{h^2} \geq 0$.

이제 $\alpha$ 근방에서, $∇^2 f(x) \geq 0$ 임을 보이면 충분하다.

증명을 위해 다음 명제가 참이라 하자.

For all $ε>0$, there exist $x \in S = [x: 0< \| x - \alpha \| \leq ε] \text{ such that } f(x)$ is non-convex. ...(3)

이 명제는 거짓이다. 왜냐하면:

먼저 $ε>0$을 선택하자. 그럼 그에 따라 $ε_0 = inf[\|x-\alpha\| : x \in S \text{ and } ∇^2f(x)<0]$를 구할 수 있다.(아래로 유계인 집합이므로, 하한이 존재한다.)

그럼 다음 세 경우를 보면 된다.
먼저 $ε_0 ≠ 0$일때 $ε = ε_0$이라 하면 (3)은 모순이 된다. . 따라서 $ε_0 = 0$일때를 보면 충분하다.

$ε_0 = 0$ 이고 $∇^2 f(\alpha) > 0$ 일 때를 보자. 그럼 $ε_0$은  $T = [\|x-\alpha\| : x \in S \text{ and } ∇^2f(x)<0]$의 극한점이 된다.(고립점이라고 하면 바로 모순이 발생한다.)

극한점이 존재하므로, $T' = [x : x \in S \text{ and } ∇^2f(x)<0]$ 안의 수열 $\{x_n\}$ 이 존재하여 $\alpha$로 수렴한다.

그럼, 극한의 정의에 따라

$∇^2 f(\alpha) = lim_{h → 0} \frac {f(\alpha + h) + f(\alpha - h)-2f(\alpha)}{h^2}$

$<=>$ For all $ε>0$ there exist $\delta>0$ such that
$\|h\|<\delta => \|∇^2 f(\alpha) -\frac {f(\alpha + h) + f(\alpha - h)-2f(\alpha)}{h^2}\| < ε$. ...(4) 이 되고,


(4)에서의 $\delta$를 선택하자. 그럼 이렇게 잡은 $\delta$에 대해 $x_n \to \alpha$에 따라
there exist $N \in \text{N}$ such that $n \geq N => \|x_n - \alpha \| < \delta$. ...(5) 이 만족된다.

By (4) and (5), 결과적으로
For all $ε>0$ there exist $N \in \text{N}$ such that
$n \geq N => \|∇^2 f(\alpha) -\frac {f(x_n) + f(2\alpha - x_n)-2f(\alpha)}{(x_n - \alpha)^2}\| < ε$. ...(6)

이 상황에서 $∇^2 f(\alpha) >0$를 전제했으므로, $ε = ∇^2 f(\alpha)$으로 잡을 때 (6)은 거짓이 된다.  따라서 (6) is false.

$ε_0 = 0$ and $∇^2 f(\alpha) = 0$일때를 보자., then $ε_0$ is limit point of $\{\|x-\alpha\| : x \in S\}$.

$∇^2 f(\alpha) = 0$ and  $f(\alpha$) is local minimum이기 때문에,
there exist $ε_2>0$ such that $\int_\alpha^{\alpha + ε_2} ∇^2 f(\alpha) > 0, \int_\alpha^{\alpha - ε_2} ∇^2 f(\alpha) > 0$.(만약 이런 $ε_2$이 존재하지 않는다면, $f$의 도함수가 0을 지나고 단조증가인것에 모순된다.)

Therefore, there exist $ε_3>0$ such that $∇^2 f(\alpha) \geq 0$, this is contradiction with (3).

Thus, Negation of (1) is false. Consequently, (1) is True.

Proof end. □


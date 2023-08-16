# Limitation of FNN: FNN can only present continuous function
<!-- 
Proposition: Continuous-Activation-funciton FNN can not approximate an arbitraliry function.

FNN can present like function,
we define function FNN as

$a^0(x) = x(=input)$, 

$a^k(x) = \sigma(W^k \cdot a^{k-1}(x) + b^k)$,
($k \in \{1,2,...L\}$),

$f_\theta(x) = W^L \cdot a^{L-1}(x) + b^L$ ( = output)

then if $\sigma$ is continuous, $f_\theta(x)$ should be continuous function.
and now, we show that -->


Question. There exist sequence of piecewise continuous functions pointwise converge to an arbitralily discontinuous function?

Proposition. Any sequence of piecewise continuous functions can not uniform converge to an arbitralily discontinuous function.

For prove this Proposition, we prove that

Theorem 1: 

There exists a sequence of piecewise continuous functions ${f_n(x)}$ that converges uniformly for any arbitrarily continuous function on $X$.

Proof of Theorem 1

Let X is bounded interval $X \subset \R$, ${f_n(x)}$ is piecewise continuous functions that satisfies Lemma 1. 


Consider an arbitrary continuous function f(x) on $X$. f(x) is Riemann-integrable by f is continuous on bounded interval, and bounded by f define on compact set. This property extends to the sequence ${f_n(x)}$. Consequently, ${f_n(x)}$ is Riemann-integrable. Therefore ${f_n(x)}$ is Lebesgue-integrable functions.

${f_n(x)}$ satisfies next two property:

1. ${\forall n \in \N, \exist g \text{ such that } |f_n| \leq g}$ by $f_n(x)$ is bounded.

2. ${f_n(x)}$ is converges pointwise by $x \in X$ by lemma 1.

so we get

$\lim_{{n \to \infty}} \int_X |{f_n(x)} - f| = 0$

by Lebesgue's dominated convergence theorem. Now we use this,

$\int_X |{f_n(x)} - f| \geq |{f_n(x)} - f|_{sup} = sup\{|{f_n(x)} - f| : x \in X\}$

then $|{f_n(x)} - f|_{sup} \to 0$.

As a result, there exists ${f_n(x)}$ that converges unifomly for any arbitrarily continuous function. 
$\qedhere$

Lemma 1: There exists a sequence of piecewise continuous functions ${f_n(x)}$ that converges pointwise for any arbitrarily continuous function on $X$.

Proof of Lemma 1:

For arbitrarily continuous function f, let define $f_n(x)$:

$f_n(x) = \frac{f(a+ \frac{b-a}{n} \cdot (k+1)) - f(a+ \frac{b-a}{n} \cdot (k))} {\frac{b-a} {n}} \cdot (x - (a+ \frac{b-a}{n} \cdot k)) + f(a+ \frac{b-a}{n} \cdot k), x \in [x_k, x_{k+1}]$

$((a=x_0, x_1, ..., x_K = b), x_k = \frac{b-a}{n} \cdot k)$

Then, we can choose $t \in [a,b] = (1-\lambda)a - \lambda b$.

According to the definition,

$a+ \frac{b-a}{n} \cdot k = x_k \leq (1-\lambda)a - \lambda b =t \leq a + \frac{b-a}{n} \cdot k = x_{k+1}$

thus $k = \lfloor \lambda n \rfloor$.

As a result,

$f_n(t) - f(t) =$ 

$f(a + \frac{b-a}{n}\cdot \lfloor \lambda n \rfloor)(1-(\lambda n -\lfloor \lambda n \rfloor))$ + 

$f(a + \frac{b-a}{n}\cdot (\lfloor \lambda n \rfloor +1))(\lambda n -\lfloor \lambda n \rfloor) - f(a + (b-a)\cdot\lambda)$.

Lemma 2:

$\frac{\lfloor ax \rfloor}{x} \to a$

Proof of Lemma 2:

$\frac{\lfloor ax \rfloor}{x} \leq a \leq \frac{\lfloor ax \rfloor +1}{x}$. Thus

$\forall \epsilon>0, \N =\lfloor\frac {1} {\epsilon} \rfloor \text{ then } n \geq N => |a - \frac{\lfloor ax \rfloor}{x}| < \epsilon$.

by Lemma 2, 

$a + \frac{b-a}{n}\cdot \lfloor \lambda n \rfloor \to a + (b-a)\cdot\lambda$.

Due to f in continuous, 

$f_n(t) - f(t) \to 0$.


<!-- 




 $\exist \epsilon > 0$, $\forall \ N$ $\exist n \text{ such that } n \geq N \wedge \ |f(x_0) - f_n(x_0)| \geq \epsilon$. -->





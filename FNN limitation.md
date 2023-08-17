# Limitation of FNN: FNN can only present continuous function

Theorem 1: 

There exists a sequence of piecewise continuous functions ${f_n(x)}$ that converges uniformly for any arbitrarily continuous function on $X$.

Proof of Theorem 1

Let X is bounded interval $X \subset \mathbb{R}$, ${f_n(x)}$ is piecewise continuous functions that satisfies Lemma 1. 


Consider an arbitrarily continuous function f(x) on $X$. f(x) is Riemann-integrable because f is continuous on bounded interval, and bounded because f define on compact set. This property extends to the sequence ${f_n(x)}$. Thus, ${f_n(x)}$ is Riemann-integrable. Therefore ${f_n(x)}$ is Lebesgue-integrable functions.

${f_n(x)}$ satisfies next two property:

1. ${\forall n \in \mathbb{N}, \exists g \text{ such that } |f_n| \leq g}$ because $f_n(x)$ is bounded.

2. ${f_n(x)}$ is converges pointwise because $x \in X$ by lemma 1.

so we get

$\lim_{{n \to \infty}} \int_X |{f_n(x)} - f| = 0$

by Lebesgue's dominated convergence theorem. Now we use this,

$\int_X |{f_n(x)} - f| \geq |{f_n(x)} - f|_{sup} = sup[|{f_n(x)} - f| : x \in X]$

then $|{f_n(x)} - f|_{sup} \to 0$.

As a result, there exists ${f_n(x)}$ that converges unifomly for any arbitrarily continuous function. 
$\blacksquare$

Lemma 1: There exists a sequence of piecewise continuous functions ${f_n(x)}$ that converges pointwise for any arbitrarily continuous function on [a,b].

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

$\forall \epsilon>0, \mathbb{N} =\lfloor\frac {1} {\epsilon} \rfloor +1 \text{ then } n \geq N => |a - \frac{\lfloor ax \rfloor}{x}| < \epsilon$.

by Lemma 2, 

$a + \frac{b-a}{n}\cdot \lfloor \lambda n \rfloor  \to a + (b-a)\cdot\lambda$.

Due to f in continuous, 

$f_n(t) - f(t) \to 0$.
$\blacksquare$


sequence of piecewise linear continuous functions이 f로 균등수렴하면 f는 연속함수이다.
따라서 어떤 sequence of piecewise linear continuous functions으로도 discontinuous function에 대해 균등수렴시킬 수 없다.
또, 어떤 연속함수에 대해 균등수렴하는 piecewise linear 함수열이 존재하고, FNN으로 이런 piecewise linear를 구성할 수 있으므로,
node 갯수를 충분히 크게 잡아 실제 함수와 근사함수의 오차의 상한을 원하는 만큼 줄일 수 있다.

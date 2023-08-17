# Limitation of FNN: FNN can only present continuous function

Theorem 1: 

There exists a sequence of piecewise continuous functions ${f_n(x)}$ that converges uniformly for any arbitrarily continuous function on $X$.

Proof of Theorem using Lebesgue's dominated convergence theorem(Error):

Let X is bounded interval $X \subset \mathbb{R}$, 

Consider an arbitrarily continuous function f(x) on $X$. 
${f_n(x)}$ is piecewise continuous functions that satisfies Lemma 1. 

Consider an arbitrarily continuous function f(x) on $X$. f(x) is Riemann-integrable because f is continuous on bounded interval, and bounded because f define on compact set. This property extends to the sequence ${f_n(x)}$. Thus, ${f_n(x)}$ is Riemann-integrable. Therefore ${f_n(x)}$ is Lebesgue-integrable functions.

${f_n(x)}$ satisfies next two property:

1. ${\forall n \in \mathbb{N}, \exists g \text{ such that } |f_n| \leq g}$ because $f_n(x)$ is bounded.

2. ${f_n(x)}$ is converges pointwise because lemma 1.

so we get

$\lim_{{n \to \infty}} \int_X |{f_n(x)} - f| = 0$

by Lebesgue's dominated convergence theorem. Now we use this,

$\int_X |{f_n(x)} - f| \geq |{f_n(x)} - f|_{sup} = sup[|{f_n(x)} - f| : x \in X]$

(error: Why $\int_X |{f_n(x)} - f| \geq |{f_n(x)} - f|_{sup}$?)

then $|{f_n(x)} - f|_{sup} \to 0$.

As a result, there exists ${f_n(x)}$ that converges unifomly for any arbitrarily continuous function.

$\blacksquare$

Proof of Theorem using :

Let X is bounded interval $X \subset \mathbb{R}$, 

Consider an arbitrarily continuous function f(x) on $X$. 
${f_n(x)}$ is piecewise continuous functions that satisfies Lemma 1. 

Consider an arbitrarily continuous function f(x) on $X$. f(x) is Riemann-integrable because f is continuous on bounded interval, and bounded because f define on compact set. This property extends to the sequence ${f_n(x)}$.

Due to $f_n(x)$ is continous in $X$ and $f_n(x)$ is define on compact set, $f_n(x)$ is uniformly continuous by Heine–Cantor theorem.

$f_n(x)$ is uniformly bounded and uniformly continuous, thus $f_n(x)$ has a uniformly convergent subsequence by Arzelà–Ascoli. We call this subsequene $g_n(x)$. Then $g_n(x)$ converge unifomly to $f(x)$ because $f_n(x)$ is pointwise converge to $f(x)$.(Real?)

As a result, any arbitary continuous function $f(x)$ has a sequence of piecewise continuous functions that converges uniformly.

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
width를 충분히 크게 잡아 실제 함수와 근사함수의 오차의 상한을 원하는 만큼 줄일 수 있다.

또, Relu FNN에서 depth를 아무리 늘려도 신경망 $f_n(x)$은 어떤 균등수렴하는 함수열이 될 수 있다.
하지만, Activation function으로 $\sigma(x) = x^2$ 와 같은 함수를 사용하면, 무한히 큰 depth에 대해 어떤 구간에 대해 $f_n(x)$이 균등수렴하지 않는 함수가 되므로,
Activation function으로 적절한 함수를 사용해야만 한다.


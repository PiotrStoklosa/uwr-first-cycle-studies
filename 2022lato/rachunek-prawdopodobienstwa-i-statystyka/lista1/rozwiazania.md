###### tags: `Rachunek Prawdopodobieństwa i Statystyka`

# Lista 1

## Zadanie 1
:::info
Sprawdzić, że:
:::
### a)
:::info
$\displaystyle\sum_{k=0}^{n}\binom{n}{k}p^k(1-p)^{n-k}=1$
:::
$\displaystyle\sum_{k=0}^{n}\binom{n}{k}p^k(1-p)^{n-k}=((1-p)+p)^n=1^n=1$

### b)
:::info
$\displaystyle\sum_{k=0}^{n}k\binom{n}{k}p^k(1-p)^{n-k}=1$
:::

$k*\binom{n}{k}=k*\frac{n!}{k!(n-k)!}=\frac{n!}{(k-1)!(n-k)!}=n*\frac{(n-1)!}{(k-1)!(n-k)!}=n*\frac{(n-1)!}{(k-1)!((n-1)-(k-1))!}=n*\binom{n-1}{k-1}$

$\displaystyle\sum_{k=0}^{n}k\binom{n}{k}p^k(1-p)^{n-k}=\displaystyle\sum_{k=1}^{n}k\binom{n}{k}p^k(1-p)^{n-k}=\displaystyle\sum_{k=1}^{n}n*p*\binom{n-1}{k-1}p^{k-1}(1-p)^{n-k}=$
$=np*\displaystyle\sum_{k=1}^{n}\binom{n-1}{k-1}p^{k-1}(1-p)^{n-k}=np*\displaystyle\sum_{k=0}^{n-1}\binom{n-1}{k}p^{k}(1-p)^{n-(k+1)}=np*\displaystyle\sum_{k=0}^{n-1}\binom{n-1}{k}p^{k}(1-p)^{n-1-k}=np*1^n=np$

## Zadanie 2
:::info
Sprawdzić, że
:::
### a)

:::info
$\displaystyle\sum_{k=0}^\infty e^{-\lambda}*\frac{\lambda^k}{k!}=1$
:::

$\displaystyle\sum_{k=0}^\infty e^{-\lambda}*\frac{\lambda^k}{k!}=e^{-\lambda}*\displaystyle\sum_{k=0}^\infty \frac{\lambda^k}{k!}=$
$=e^{-\lambda}*(\frac{\lambda^0}{0!}+\frac{\lambda^1}{1!}+\frac{\lambda^2}{2!}+...)=e^{-\lambda}*e^\lambda=e^{-\lambda+\lambda}=e^0=1$


### b)

:::info
$\displaystyle\sum_{k=0}^\infty k*e^{-\lambda}*\frac{\lambda^k}{k!}=\lambda$
:::

$\displaystyle\sum_{k=0}^\infty k*e^{-\lambda}*\frac{\lambda^k}{k!}=e^{-\lambda}*\displaystyle\sum_{k=1}^\infty k*\frac{\lambda^k}{k!}=e^{-\lambda}*\displaystyle\sum_{k=1}^\infty \frac{\lambda^k}{(k-1)!}=e^{-\lambda}*\displaystyle\sum_{k=1}^\infty\lambda*\frac{\lambda^{k-1}}{(k-1)!}=$
$=e^{-\lambda}*\lambda*\displaystyle\sum_{k=1}^\infty\frac{\lambda^{k-1}}{(k-1)!}=e^{-\lambda}*\lambda*e^{\lambda}=\lambda$

## Zadanie 3
:::info
$\Gamma(p)=\displaystyle\int_0^\infty t^{p-1}e^{-t}dt,\quad p>0$


Wykazać, że $\Gamma(n)=(n-1)!,\quad n\in\mathbb{N}$
:::

Indkucja po $n$

**$1^\circ$**
dla $n=1$
$\Gamma(1)=\displaystyle\int_0^\infty t^{1-1}e^{-t}dt=\displaystyle\int_0^\infty e^{-t}dt=-e^{-t}\Big|^\infty_0=0-(-1)=1$

**$2^\circ$**
Załóżmy, że dla $n\in\mathbb{N}$ $\quad\Gamma(n)=(n-1)!$
Wtedy, dla $n+1$

$\Gamma(n+1)=\displaystyle\int_0^\infty t^n*e^{-t}dt=\displaystyle\int_0^\infty t^n*(-e^{-t})'dt=-\frac{t^n}{e^t}\Big|^\infty_0-\displaystyle\int_0^\infty nt^{n-1}*-e^{-t}dt=\\=-\frac{t^n}{e^t}\Big|^\infty_0+\displaystyle\int_0^\infty nt^{n-1}*e^{-t}dt=0+0+n*\displaystyle\int_0^\infty t^{n-1}*e^{-t}dt=n*\Gamma(n)=n!$

Na podstawie indukcji matematycznej dla $n\in\mathbb{N}$ $\quad\Gamma(n)=(n-1)!$
$\qquad\qquad\qquad\qquad\qquad\qquad\qquad\blacksquare$

## Zadanie 4
:::info
Niech $f(x)=\lambda\exp(-\lambda x), \text{ gdzie }\lambda>0$. Oblicz wartość całek:
:::
### a)
:::info
$\displaystyle\int_0^\infty f(x)dx$
:::
$\displaystyle\int_0^\infty f(x)dx=\displaystyle\int_0^\infty \lambda\exp(-\lambda x)dx=\lambda\displaystyle\int_0^\infty\exp(-\lambda x)dx=\lambda*\frac{-\exp(-\lambda x)}{\lambda}\Big|^\infty_0=\\=-\exp(-\lambda x)\Big|^\infty_0=0-(-1)=1$
### b)
:::info
$\displaystyle\int_0^\infty xf(x)dx$
:::
$\displaystyle\int_0^\infty xf(x)dx=\displaystyle\int_0^\infty x\lambda\exp(-\lambda x)dx=\lambda\displaystyle\int_0^\infty x\exp(-\lambda x)dx=\lambda\displaystyle\int_0^\infty x*(\frac{-\exp(-\lambda x)}{\lambda})'dx=\\=\lambda(x*\frac{-\exp(-\lambda x)}{\lambda}\Big|^\infty_0 - \displaystyle\int_0^\infty\frac{-\exp(-\lambda x)}{\lambda})=\lambda(x*\frac{-\exp(-\lambda x)}{\lambda}\Big|^\infty_0 + \displaystyle\int_0^\infty\frac{\exp(-\lambda x)}{\lambda})=\\=\lambda(x*\frac{-\exp(-\lambda x)}{\lambda}\Big|^\infty_0 + \frac{1}{\lambda}\displaystyle\int_0^\infty\exp(-\lambda x))=-x*\exp(-\lambda x)\Big|^\infty_0 + \displaystyle\int_0^\infty\exp(-\lambda x)=\\=-x*\exp(-\lambda x)\Big|^\infty_0-\frac{exp(-\lambda x)}{\lambda}\Big|^\infty_0=-\exp(-\lambda x)(x+\frac{1}{\lambda})\Big|^\infty_0=\frac{-\exp(-\lambda x)*(x\lambda+1)}{\lambda}\Big|^\infty_0=\\=-\frac{x\lambda+1}{e^{\lambda x}*\lambda}\Big|^\infty_0=-0-(-\frac{1}{\lambda})=\frac{1}{\lambda}$

## Zadanie 5

:::info
Wykazać, że $D_n=n$, gdzie
![](https://i.imgur.com/W6d0Qgo.png)
:::

Dodajemy do pierwszego wiersza kolejno drugi, trzeci, ..., n-ty wiersz otrzymując
macierz 
![](https://i.imgur.com/xsZyknk.png)
Powstała macierz jest macierzą trójkątną, więc wystarczy przemnożyć wszystkie liczby po przekątnej:
$D_n=n*1*1*...*1=n$
$\qquad\qquad\qquad\qquad\qquad\qquad\qquad\blacksquare$

## Zadanie 7
:::info
Symbol $\overline{s}$ oznacza średnią ciągu $s_1,...,s_n$. Udowodnić, że:
:::
### a)
:::info
$\displaystyle\sum^n_{k=1}(x_k-\overline{x})^2=\displaystyle\sum^n_{k=1}x_k^2-n*\overline{x}^2$
:::
Dowód przedstawiony w podpunkcie [b)](#b3) dla ciągu $y=x$

### b)

:::info
$\displaystyle\sum^n_{k=1}(x_k-\overline{x})(y_k-\overline{y})=\displaystyle\sum^n_{k=1}x_k*y_k-n\overline{x}\overline{y}$
:::

$\displaystyle\sum^n_{k=1}(x_k-\overline{x})(y_k-\overline{y})=\displaystyle\sum^n_{k=1}(x_ky_k-\overline{y}x_k-\overline{x}y_k+\overline{x}\overline{y})=\\=\displaystyle\sum^n_{k=1}x_ky_k-\displaystyle\sum^n_{k=1}\overline{y}x_k-\displaystyle\sum^n_{k=1}\overline{x}y_k+\displaystyle\sum^n_{k=1}\overline{x}\overline{y}=\displaystyle\sum^n_{k=1}x_ky_k-\overline{y}\displaystyle\sum^n_{k=1}x_k-\overline{x}\displaystyle\sum^n_{k=1}y_k+n\overline{x}\overline{y}=\\=\displaystyle\sum^n_{k=1}x_ky_k-\overline{y}n\overline{x}-n\overline{x}\overline{y}+n\overline{x}\overline{y}=\displaystyle\sum^n_{k=1}x_k*y_k-n\overline{x}\overline{y}$
$\qquad\qquad\qquad\qquad\qquad\qquad\qquad\blacksquare$
## Zadanie 8

:::info
Dane są wektory $\vec{\mu}$, $X\in\mathbb{R}^n$ oraz macierz $\sum\in\mathbb{R}^{n\space x\space n}$. Niech $S = (X − \vec{\mu})^T \sum^{−1}(X − \vec{\mu})$ oraz
Y = A · X, gdzie macierz A jest odwracalna. Sprawdzić, że $S = (Y − A \vec{\mu})^T (A\sum A^T )^{-1}(Y − A\vec{\mu})$.
:::

Z własności macierzy:

$(AB)^T=B^TA^T$
$(ABC)^T=C^TB^TA^T$
$(AB)^{-1}=B^{-1}A^{-1}$
$(ABC)^{-1}=C^{-1}B^{-1}A^{-1}$

Wyjście z prawej do lewej strony:

$S=(Y − A \vec{\mu})^T (A\sum A^T )^{-1}(Y − A\vec{\mu})=(AX − A \vec{\mu})^T (A\sum A^T )^{-1}(AX − A\vec{\mu})=\\=(A(X − \vec{\mu}) )^T (A\sum A^T )^{-1}(A(X − \vec{\mu}))=(X − \vec{\mu})^TA^T(A\sum A^T )^{-1}A(X − \vec{\mu})=\\=(X − \vec{\mu})^TA^T(A^T)^{-1}\sum^{-1}A^{-1} A(X − \vec{\mu})=(X − \vec{\mu})^T\sum^{-1}(X − \vec{\mu})$
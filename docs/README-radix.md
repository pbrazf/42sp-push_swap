# Radix Sort no push_swap (Resumo Rápido)

## 🎯 Ideia Central
Ordenar pelos **bits** do índice (0..n-1), do bit menos significativo para o mais significativo.  
Cada rodada separa elementos em dois grupos:

- **bit = 0 → B**
- **bit = 1 → A**

Depois junta tudo de volta: `pa`.

Isso preserva a **ordem relativa** dentro de cada grupo → ordenação estável.  
Repetir isso para todos os bits = lista totalmente ordenada.

---

## 🧠 Por que funciona?
Porque cada bit organiza "blocos":

- bit 0 → blocos de 1 (pares vs ímpares)  
- bit 1 → blocos de 2  
- bit 2 → blocos de 4  
- bit 3 → blocos de 8  
- …

Cada rodada refina o nível de ordenação anterior.  
No último bit, o bloco final cobre todos os números → ordenado.

---

## 🔧 Como o algoritmo usa as pilhas
**A** = grupo dos índices com bit = 1  
**B** = grupo com bit = 0

Fluxo para cada bit:

1. Para cada nó de A:
   - bit = 1 → `ra`
   - bit = 0 → `pb`
2. Quando terminar, devolve tudo de B → `pa`

Somente isso.

---

## ✔️ Intuição final
- Você só precisa de **duas pilhas** porque sempre existem apenas **dois grupos** por bit.  
- Como a ordem dentro de cada grupo é preservada, a combinação final vira a ordem crescente natural.  
- Repetir para todos os bits reconstrói a ordem completa de 0..n-1.

---

## 📝 Exemplo curtíssimo
Índices: `3 1 0 2`

Bit 0:
- 3→1, 1→1, ficam  
- 0→0, 2→0, vão para B
→ A = [3,1], B = [0,2] → `pa pa` → [3,1,0,2]

Bit 1:
- 3→1, 2→1  
- 1→0, 0→0  
→ A = [3,2], B = [1,0] → `pa pa` → **[3,2,1,0]** (ordenado em índice)

---

## 🔥 Lembrar sempre
> “Radix = ordenar por blocos cada vez maiores.  
> A estabilidade garante que tudo se encaixe no final.”


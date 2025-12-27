# 📘 Push_swap — Resumo Ultra Rápido

### ✔️ Execução + Checker
```
./push_swap <nums> | ./checker_linux <nums>
```

### ✔️ Operações válidas
```
sa sb ss
pa pb
ra rb rr
rra rrb rrr
```

### ✔️ Regras de saída
- apenas operações
- uma por linha
- entrada já ordenada → nenhuma saída

### ✔️ Sorts
- 3 números → sa / ra / rra
- 4–5 números → empurra menores para B → volta com pa
- >5 números → radix com index

### ✔️ Benchmarks
- aprovado (80%):
  - 100 números < 1100
  - 500 números < 8500

### ✔️ Testes rápidos
```
ARG=($(seq 1 500 | shuf))
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l
```

### Operações

✅ Operações usadas
- sa
- pa
- pb
- ra
- rra

❌ Operações não usadas em nenhum momento
- sb
- ss
- rb
- rrb
- rr
- rrr

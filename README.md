# Teclado Matricial com Raspberry Pi Pico na BitDogLab

Este projeto implementa a leitura de um teclado matricial 4x4 utilizando uma placa Raspberry Pi Pico (RP2040) na plataforma BitDogLab. O sistema detecta qual tecla foi pressionada e exibe o caractere correspondente no terminal serial, servindo como um exemplo fundamental de entrada de dados para projetos embarcados.

---

## ⚙️ Funcionalidades

-   **Leitura de Teclado Matricial:** Varredura de linhas e colunas para identificar a tecla pressionada em um teclado 4x4.
-   **Exibição em Terminal Serial:** Envio do caractere correspondente à tecla pressionada para o monitor serial.
-   **Debounce Simples:** Implementação de uma lógica de software para evitar leituras múltiplas de um único pressionamento de tecla.
-   **Código Limpo:** Escrito em C/C++ utilizando o SDK oficial do Raspberry Pi Pico.

---

## 📋 Pré-requisitos

Antes de começar, garanta que você tenha os seguintes itens:

-   **Hardware:**
    -   Placa BitDogLab (com RP2040)
    -   Teclado Matricial 4x4
-   **Software:**
    -   Ambiente de desenvolvimento C/C++ para Pico SDK devidamente configurado.

---

## 🔌 Montagem do Circuito

A conexão entre os pinos do teclado e as portas GPIO da Pico é direta. Para o **Kit Básico do Embarcatech**, a pinagem correta utilizada neste projeto é a seguinte:

| Pino do Teclado | Conectar na Porta GPIO do Pico |
| :-------------- | :----------------------------- |
| Linha 1 (L1)    | GP4                            |
| Linha 2 (L2)    | GP8                            |
| Linha 3 (L3)    | GP9                            |
| Linha 4 (L4)    | GP16                           |
| Coluna 1 (C1)   | GP17                           |
| Coluna 2 (C2)   | GP18                           |
| Coluna 3 (C3)   | GP19                           |
| Coluna 4 (C4)   | GP20                           |

---

## 🚀 Como compilar e executar

### 1. Clone o repositório e configure o Pico SDK:

Assumindo que o Pico SDK já está configurado, clone este repositório e compile o projeto.

```bash
# Clone o repositório
git clone https://github.com/LabirasIFPI/bitdoglab_teclado_matricial
cd bitdoglab_teclado_matricial

# Crie e acesse o diretório de build
mkdir build && cd build

# Gere os arquivos de compilação com o CMake
cmake ..

# Compile o projeto
make
```

### 2. Grave o arquivo .uf2 gerado na Pico:

-   Conecte a Pico ao seu computador enquanto mantém o botão **BOOTSEL** pressionado.
-   A placa será montada como um dispositivo de armazenamento em massa (uma unidade USB).
-   Copie o arquivo `.uf2` (que estará dentro da pasta `build`) para a unidade USB que apareceu. A placa irá reiniciar automaticamente.

### 3. Conecte o hardware:

-   Com a placa desligada, conecte o teclado matricial aos pinos GPIO conforme a tabela de **Montagem do Circuito**.

### 4. Execute:

-   Conecte-se à porta serial da sua Raspberry Pi Pico utilizando um monitor serial (ex: PuTTY, a ferramenta de serial do VS Code, etc.) com a taxa de 115200 bauds.
-   O sistema iniciará automaticamente.
-   Ao pressionar qualquer tecla no teclado matricial, o caractere correspondente será exibido no terminal.

---

## 💡 Observações

-   A pinagem definida no código é baseada no conector do **Kit Básico do Embarcatech**. Se você estiver usando uma pinagem diferente, lembre-se de atualizar os arrays `row_pins` e `col_pins` no arquivo `main.c`.
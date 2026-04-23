# Documentação SA1 Parte 1 e Parte 2

## Contexto
Nesta documentação, apresentaremos o contexto relacionado ao projeto SA1, que visa gerir requisições de saúde de forma eficiente e organizada.

## Objetivos
Os principais objetivos deste projeto são:
1. Desenvolver um sistema que permita a gestão de requisições de saúde.
2. Facilitar a comunicação entre os profissionais de saúde e os pacientes.
3. Prover uma interface amigável para os usuários.

## Estruturas de Dados
As estruturas de dados utilizadas incluem:
- `Requisicao`
  - `id`: Identificador único da requisição.
  - `paciente`: Informações sobre o paciente.
  - `status`: Estado da requisição (pendente, em andamento, finalizada).
- `Saude`
  - `id`: Identificador único da saúde.
  - `descricao`: Descrição detalhada da saúde solicitada.

## Funções Obligatoriais
As funções obrigatórias do sistema incluem:
- `criarRequisicao(paciente, saude)`
- `atualizarStatusRequisicao(id, novoStatus)`
- `listarRequisicoes()`

## Testes
Os testes devem cobrir todos os casos de uso possíveis, incluindo:
- Criação de requisições.
- Atualização de status.
- Listagem de requisições.

## Critérios de Avaliação
Os critérios para avaliação do projeto são:
- Eficiência do sistema ao lidar com grandes volumes de requisições.
- Usabilidade da interface para os usuários finais.
- Precisão dos dados apresentados nas requisições.
# RedeSocial
Trabalho feito como avaliação da matéria Algoritmo e Estrutura de dados (ENG. COMPUTAÇÃO CEFET)
## Sobre o projeto
Ao iniciar o programa, a rede social apresenta ao usuário a opção de criar uma conta (escolhendo um nome
de usuário e uma senha), ou logar em uma já existente. Ao entrar na conta, um menu é disponibilizado ao
usuário onde ele é ser capaz de interagir com diversas funcionalidades da rede social:

**1) Perfil**: O perfil é onde o usuário guarda informações sobre si mesmo, tais como nome completo, ocupação social,
endereço e biografia. O usuário é capaz de visualizar o perfil de qualquer outro usuário (incluindo a si
mesmo) e também é capaz de editar seu próprio perfil;

**2) **Mural:** O mural é onde o usuário pode fazer suas postagens de texto, também conhecido como "blog pessoal".
O usuário também é capaz de ver o mural completo de qualquer outro usuário;

**3) Lista de amigos:** O usuário pode adcionar diversos amigos através do nome de cada usuário (não é
necessário solicitação de amizade). O usuário é capaz de visualizar a lista de amigos de qualquer outro
usuário. Essa lista mostra o nome de usuário dos amigos em ordem alfabética;

**4) Mensagens:** O usuário pode enviar mensagens para outros usuários e também receber mensagens em uma
caixa de entrada. Ao acessar essa funcionalidade, todas as mensagens na caixa de entrada são mostradas em
ordem cronológica (mostrando claramente qual usuário enviou qual mensagem) e, assim que visualizadas, essas
mensagens são automaticamente apagadas da memória, permitindo que a caixa de entrada contenha apenas
mensagens ainda não lidas;

**5) Troca de senha:** É permitido ao usuário trocar sua senha. Por motivos de segurança, a senha atual do
usuário é pedida antes da senha nova;

**6) Grupos:** Usuários podem criar ou entrar em grupos. Cada grupo é criado com um nome único, possui um íıder
(o usuário que criou o grupo) e o grupo pode possuir uma descrição. Grupos possuem seu próprio mural, onde
os participantes daquele grupo podem fazer postagens as quais qualquer pessoa (incluindo pessoas de fora do
grupo) podem visualizar. Para que os usuários possam conhecer novos grupos e decidir se querem participar de
algum, é possível ao usuário ver uma lista completa, em ordem alfabética, de todos os grupos existentes.

Por fim, é permitido ao usuário “deslogar” de sua conta, o que faz o programa voltar à tela de login, onde
outro usuário pode logar em seu lugar.

## Tecnologias utilizadas

**1)** Programa feito em linguagem C.

## Como Executar o programa

**1)** Executar git clone https://github.com/leeymattos/RedeSocial

**2)** Com o diretório dos arquivos .c e .h abertos em um terminal compilar o projeto (compilador gcc é cumumente usado
para essa tarefa)

**3)** executar o projeto com (./a.out)

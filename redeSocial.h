/**
 * @file redeSocial.h
 * @author Weslley de Matos Cabral
 * @date Maio 2021
 * @brief Arquivo contendo bibliotecas, structs e funções que serão utilizadas no projeto da rede social.
 * 
 * Foi feita uma implementação de listas, tanto duplamente encadeadas como simples para fazer
 * as operações necessárias para o projeto.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Estrutura para guardar as informações de perfil de um usuário.
*/

typedef struct perfil
{
  char full_Name[251]; /**<Nome completo da pessoa*/
  char social_occupation[61]; /**<Ocupação social da pessoa*/
  char adress[251]; /**<Endereço da pessoa*/
  char biography[251]; /**<Biografia da pessoa*/
} perfil;

/**
 * @brief Estrutura para criar a lista de posts que uma pessoa pode fazer.
 * Nesse caso é uma lista encadeada simples, cada nó só aponta para o próximo post da lista.
*/

typedef struct posts
{
  char userName[21]; /**<Nome do usuário que fez o post, essa informação será mais necessária no post dos grupos*/
  char postText[1025]; /**<O Conteúdo do post*/

  struct posts *nextpost; /**<ponteiro que aponta para o próximo post*/
} posts;


/**
 * @brief Estrutura para criar lista de amigo que uma pessoa pode ter.
 * Nesse caso é uma lista duplamente encadeada, cada nó tem um ponteiro que aponta para o próximo
 * da lista e para seu anterior.
 * Essa lista fica ordenada de maneira crescente por consequência da função que registra cada 
 * novo amigo da pessoa.
*/

typedef struct friends
{
  char name[21]; /**<Nome do amigo da pessoa*/

  struct friends *nextFriend; /**<Ponteiro que aponta para o próximo amigo da lista*/
  struct friends *previosFriend; /**<Ponteiro que aponta para o amigo anterior da lista*/
} friends;

/**
 * @brief Estrutura para criar a lista de mensagens que a pessoa poderá receber.
 * Nesse caso é uma lista encadeada simples, cada nó só aponta para a próxima mensagem da lista.
 * Cada nova mensagem é adcionada ao final da lista para que a pessoa possa ver a mensagem de maneira cronológica.
*/

typedef struct messages
{
  char name[21]; /**<Nome da pessoa que enviou a mensagem*/
  char messageText[251]; /**<Conteúdo da mensagem*/

  struct messages *nextMessage; /**Ponteiro que aponta para a próxima mensagem da lista*/
} messages;

/**
 * @brief Estrutura para criar a lista de usuários.
 * Nesse caso é uma lista duplamente encadeada, cada nó tem um ponteiro que aponta para o próximo
 * da lista e para seu anterior.
 * Essa lista fica ordenada de maneira crescente por consequência da função que registra cada
 * novo usuário.
*/

typedef struct user
{

  char user_name[21]; /**<Nome de usuário uníco*/
  char password[21]; /**<Senha uníca do usuário*/

  struct user *next; /**<Ponteiro para o próxomo usuário da lista*/
  struct user *prev; /**<Ponteiro para o usuário anterior da lista*/
  struct perfil *perfil; /**<Ponteiro para a estrutura de perfil única do usuário*/
  struct posts *posts; /**Ponteiro para o cabeça da lista de posts*/
  struct friends *friends; /**Ponteiro para o cabeça da lista de amigos*/
  struct messages *messages; /**Ponteiro para o cabeça da lista de mensagens*/

} user;

/**
 * @brief Estrutura para criar a lista de grupos.
 * Nesse caso é uma lista duplamente encadeada, cada nó tem um ponteiro que aponta para o próximo
 * da lista e para seu anterior.
 * Essa lista fica ordenada de maneira crescente por consequência da função que registra cada
 * novo grupo.
*/

typedef struct group
{
  char groupName[51]; /**<Nome único do grupo*/
  char leaderName[21]; /**<Nome do líder do grupo*/
  char description[251]; /**<conteúdo da descrição do grupo*/

  struct posts *posts;  /**<Ponteiro que aponta para o cabeça da lista de posts do grupo*/
  struct friends *members; /**<Ponteiro que aponta para o cabeça da lista de membros do grupo*/

  struct group *nextGroup; /**<Ponteiro que aponta para o próximo da lista*/
  struct group *previosGroup; /**<Ponteiro que aponta para o grupo anterios da lista*/
} group;

/**
 * @brief Busca por um amigo através do nome de usuário.
 * @param head Nó cabeça da lista de amigos
 * @param name Nome do usuário que deseja procurar na lista de amigos
 * @return Retorna o amigo buscado ou o nó cabeça caso não tenha
 * sido encontrado na lista.
*/
friends *findFriend(friends *head, char *name);

/**
 * @brief Adciona um amigo a lista de amigos do usuário.
 * @param head Nó cabeça da lista de amigos
 * @param name Nome do usuário que deseja adcionar como amigo
*/
void addFriend(friends *head, char *name);

/**
 * @brief Inclui um novo membro no grupo.
 * @param head Nó cabeça da lista de amigos
 * @param name Nome do usuário que deseja incluir no grupo
*/
void includeMenber(friends *head, char *name);

/**
 * @brief Procura por um grupo
 * @param head Nó cabeça da lista de grupos
 * @param groupName Nome do grupo a ser procurado
 * @return Retorna o nó do grupo buscado ou o nó cabeça caso o grupo não tenha sido encontrado
 * na lista
*/
group *findGroup(group *head, char *groupName);


/**
 * @brief Cria um novo grupo e adciona ele a lista de grupos.
 * @param head Nó cabeça da lista de grupos
 * @param groupName Nome do grupo
 * @param leaderName Nome do líder
 * @param description Descrição do grupo
*/
void createGroup(group *head, char *groupName, char *leaderName, char *description);


/**
 * @brief Cria um novo post no mural do usuário
 * @param hasUser Nó do usuário que vai fazer o post
 * @param postText Conteúdo do Post 
*/
void MakePost(user *hasUser, char *postText);

/**
 * @brief Criar um novo post no mural do grupo
 * @param hasUser Nó do usuário que vai fazer o post
 * @param hasGroup Nó do grupo onde vai publicar
 * @param postText Conteúdo do post
*/
void MakePostGroup(user *hasUser, group *hasGroup, char *PostText);

/**
 * @brief Envia mensagem para um amigo
 * @param hasUser Nó do usuário para quem será enviada a mensagem
 * @param messageText Conteúdo da mensagem
 * @param name Nome do usuário que enviou a mensagem
*/
void SendMessage(user *hasUser, char *messageText,char *name);


/**
 * @brief Registra um perfil de usuário
 * @param hasUser Nó do usuário que será registrado o perfil
 * @param fullName Nome todo do usuário
 * @param socialOccupation Ocupação social do usuário
 * @param adress Endereço do usuário
 * @param biography Biográfia do usuário
*/
void registerPerfil(user *hasUser, char *fullName, char *socialOccupation, char *adress, char *briography);

/**
 * @brief Procura por um usuário
 * @param head Nó cabeça da lista de usuários
 * @param userName Nome de usuário a ser procurado
 * @return Retorna o nó do usuário buscado ou o nó cabeça caso o grupo não tenha sido encontrado
 * na lista
*/
user *findUser(user *head, char *userName);

/**
 * @brief Registra um novo usuário
 * @param head Nó cabeça da lista de usuários
 * @param userName Nome do usuário a ser criado
 * @param password Senha do usuário a ser criado
*/
void registerUser(user *head, char *userName, char *password);

/**
 * @brief Mostrar o perfil
 * @param hasUser Nó do usuário a ser printado o perfil
*/
void printPerfil(user *hasUser);

/**
 * @brief Mostrar posts de um usuário
 * @param hasUser Nó do usuário a ser printado os posts
*/
void printPosts(user *hasUser);

/**
 * @brief Mostrar posts de um grupo
 * @param hasUser Nó do grupo a ser printado os posts
*/
void printPostsGroup(group *hasGroup);

/**
 * @brief Mostrar amigos de um usuário
 * @param head Cabeça da lista de amigos
*/
void printFriends(friends *head);


/**
 * @brief Mostrar mensagens de um usuário e apagar todas elas
 * @param hasUser Nó do usuário a ser mostrada as mensagens
*/
void printMessages(user *hasUser);

/**
 * @brief Mostrar todos os grupos
 * @param head Cabeça da lista de grupos
*/
void printGroups(group *head);

/**
 * @brief Saber se a string contém a palavra "sair"
 * @param vet1 string a ser analisada
 * @return Retorna 1 caso contenha a palavra "sair" e retorna 0 caso não tenha
*/
int needBack(char *vet1);

/**
 * @brief Limpa a memória usada em toda a lista de usuários e as demais listas incluídas dentro
 *  da lista de usuários (lista de amigos, lista de posts, lista de mensagens)
 * @param head Nó cabeça da lista de usuários
*/
void freeUsers(user * head);

/**
 * @brief Limpa a memória usada em toda lista de grupos e as demais listas incluídas dentro da
 * lista de grupos (lista de membros, lista de postagens)
 * @param head Nó cabeça da lista de grupos
*/
void freeGroups(group *head);
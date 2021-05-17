#include "redeSocial.h"

char keyboard[BUFSIZ];

friends *findFriend(friends *head, char *name)
{

  strcpy(head->name, name);

  friends *p = head->nextFriend; //primeiro cara

  while (strcmp(p->name, name) < 0)
  {
    p = p->nextFriend;
  }
  return p;
}

void addFriend(friends *head, char *name)
{
  system("cls || clear");
  friends *pont = findFriend(head, name);

  int aux = strcmp(pont->name, name);

  if (pont == head || aux != 0)
  {
    friends *q = pont->previosFriend;
    friends *p = malloc(sizeof(friends));

    strcpy(p->name, name);

    p->nextFriend = pont;
    p->previosFriend = q;
    q->nextFriend = p;
    pont->previosFriend = p;

    printf("Usuário '%s' adcionado a lista de amigos.\n", name);
  }
  else
  {
    printf("Amigo já tinha sido adcionado anteriormente\n");
  }
}

void includeMenber(friends *head, char *name)
{
  system("cls || clear");
  friends *pont = findFriend(head, name);

  int aux = strcmp(pont->name, name);

  if (pont == head || aux != 0)
  {
    friends *q = pont->previosFriend;
    friends *p = malloc(sizeof(friends));

    strcpy(p->name, name);

    p->nextFriend = pont;
    p->previosFriend = q;
    q->nextFriend = p;
    pont->previosFriend = p;

    printf("Você foi adcionado a lista de membros do grupo.\n");
  }
  else
  {
    printf("Você já faz parte desse grupo.\n");
  }
}

group *findGroup(group *head, char *groupName)
{
  strcpy(head->groupName, groupName);

  group *p = head->nextGroup; //primeiro cara

  while (strcmp(p->groupName, groupName) < 0)
  {
    p = p->nextGroup;
  }
  return p;
}

void createGroup(group *head, char *groupName, char *leaderName, char *description)
{
  system("cls || clear");

  group *pont = findGroup(head, groupName);
  int aux = strcmp(pont->groupName, groupName);

  if (pont == head || aux != 0)
  {
    group *q = pont->previosGroup;
    group *p = malloc(sizeof(group));

    strcpy(p->groupName, groupName);
    strcpy(p->leaderName, leaderName);
    strcpy(p->description, description);

    p->nextGroup = pont;
    p->previosGroup = q;
    q->nextGroup = p;
    pont->previosGroup = p;

    posts *post = malloc(sizeof(posts));
    post->nextpost = NULL;
    p->posts = post;

    friends *member = malloc(sizeof(friends));
    member->nextFriend = member;
    member->previosFriend = member;
    p->members = member;

    includeMenber(p->members, leaderName);

    printf("Grupo '%s' criado com sucesso.\n", groupName);
  }
  else
  {
    printf("Nome de grupo já está em uso.\n");
  }
}

void MakePost(user *hasUser, char *postText)
{

  posts *pont = hasUser->posts; //cabeça

  posts *newPost = malloc(sizeof(posts));

  strcpy(newPost->userName, hasUser->user_name);
  strcpy(newPost->postText, postText);

  newPost->nextpost = pont->nextpost;
  pont->nextpost = newPost;

  printf("Post foi criado com sucesso!\n");
}

void MakePostGroup(user *hasUser, group *hasGroup, char *postText)
{

  posts *pont = hasGroup->posts; //cabeça

  posts *newPost = malloc(sizeof(posts));

  strcpy(newPost->userName, hasUser->user_name);
  strcpy(newPost->postText, postText);

  newPost->nextpost = pont->nextpost;
  pont->nextpost = newPost;

  printf("Post foi criado com sucesso!\n");
}

void SendMessage(user *hasUser, char *messageText, char *name)
{
  system("cls || clear");
  messages *pont = hasUser->messages;

  while (pont->nextMessage != NULL)
  {
    pont = pont->nextMessage;
  }
  messages *newMessage = malloc(sizeof(messages));

  strcpy(newMessage->messageText, messageText);
  strcpy(newMessage->name, name);

  newMessage->nextMessage = NULL;
  pont->nextMessage = newMessage;

  printf("Mensagem enviada com sucesso!\n");
}

void registerPerfil(user *hasUser, char *fullName, char *socialOccupation, char *adress, char *briography)
{

  if (hasUser->perfil != NULL)
  {
    strcpy(hasUser->perfil->adress, adress);
    strcpy(hasUser->perfil->biography, briography);
    strcpy(hasUser->perfil->full_Name, fullName);
    strcpy(hasUser->perfil->social_occupation, socialOccupation);
    printf("Perfil atualizado!\n");
    return;
  }

  perfil *p = malloc(sizeof(perfil));

  strcpy(p->adress, adress);
  strcpy(p->biography, briography);
  strcpy(p->full_Name, fullName);
  strcpy(p->social_occupation, socialOccupation);

  hasUser->perfil = p;
  printf("Perfil atualizado.\n");
}

user *findUser(user *head, char *userName)
{

  strcpy(head->user_name, userName);

  user *p = head->next;

  while (strcmp(p->user_name, userName) < 0)
  {
    p = p->next;
  }
  return p;
}

void registerUser(user *head, char *userName, char *password)
{

  user *pont = findUser(head, userName);

  int aux = strcmp(pont->user_name, userName);

  if (pont == head || aux != 0)
  {

    user *q = pont->prev; //cabeça
    user *p = malloc(sizeof(user));

    strcpy(p->user_name, userName);
    strcpy(p->password, password);

    p->next = pont; //vai apontar para weslley
    p->prev = q;    //vai apontar para o cabeça
    q->next = p;    //cabeça aponta para jose
    pont->prev = p; //weslley aponta para jose

    p->perfil = NULL;

    posts *post = malloc(sizeof(post));
    post->nextpost = NULL;
    p->posts = post;

    messages *message = malloc(sizeof(messages));
    message->nextMessage = NULL;
    p->messages = message;

    friends *friend = malloc(sizeof(friends));
    friend->nextFriend = friend;
    friend->previosFriend = friend;
    p->friends = friend;

    printf("Usuário '%s' criado com sucesso.\n", userName);
  }
  else
  {
    printf("Nome de Usuário já cadastrado.\n");
  }
}

void printPerfil(user *hasUser)
{
  user *p = hasUser;

  printf("Nome de usuário: %s\n", p->user_name);
  if (p->perfil == NULL)
  {
    printf("Ainda não criou o seu perfil\n\n");
    return;
  }

  printf("Nome completo: %s\n", p->perfil->full_Name);
  printf("Ocupação social: %s\n", p->perfil->social_occupation);
  printf("Endereço: %s\n", p->perfil->adress);
  printf("Biografia: %s\n\n", p->perfil->biography);
}

void printPosts(user *hasUser)
{
  system("cls || clear");
  posts *post = hasUser->posts->nextpost; // primeiro cara

  if (post == NULL)
  {
    printf("Usuário ainda não fez uma postagem.\n");
    return;
  }

  posts *aux = NULL;

  while (post != NULL)
  {
    printf("%s: %s\n\n", post->userName, post->postText);
    post = post->nextpost;
  }
}

void printPostsGroup(group *hasGroup)
{
  system("cls || clear");
  posts *post = hasGroup->posts->nextpost; // primeiro cara

  if (post == NULL)
  {
    printf("Grupo ainda não tem postagens.\n");
    return;
  }

  posts *aux = NULL;

  while (post != NULL)
  {
    printf("%s: %s\n\n", post->userName, post->postText);
    post = post->nextpost;
  }
}

void printFriends(friends *head)
{

  friends *p = head->nextFriend;

  if (p == head)
  {
    printf("Usuário ainda não adicionou um amigo\n");
  }

  while (p != head)
  {
    printf("%s\n", p->name);
    p = p->nextFriend;
  }
  printf("\n");
}

void printMessages(user *hasUser)
{
  system("cls || clear");
  messages *message = hasUser->messages->nextMessage; //primeiro cara
  messages *firstMessage = hasUser->messages;

  messages *aux = NULL;

  if (message == NULL)
  {
    printf("Não tem novas mensagens\n");
    return;
  }

  while (message != NULL)
  {
    printf("%s: %s\n\n", message->name, message->messageText);
    aux = message;
    message = message->nextMessage;
    free(aux);
  }
  firstMessage->nextMessage = NULL;
}

void printGroups(group *head)
{

  group *p = head->nextGroup;

  if (p == head)
  {
    printf("Não existe grupos criados.\n");
    return;
  }

  printf("Grupos:\n");

  while (p != head)
  {
    printf("%s\n", p->groupName);
    p = p->nextGroup;
  }
  printf("\n");
}

int needBack(char *vet1)
{
  char vet2[] = "sair";

  if (strcmp(vet1, vet2) == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void freeUsers(user * head){
   user *p = head->next; //primeio cara
   user *aux = NULL;

   posts *auxPosts = NULL;
   posts *posts = NULL;

   messages *auxMessages = NULL;
   messages *messages = NULL;

   friends *auxFriends = NULL;
   friends *friends = NULL;

  while (p != head)
  {
    aux = p;
    p = p->next;
    free(aux->perfil);

    posts = aux->posts->nextpost; //primeiro cara
    while (posts != NULL)
    {
      auxPosts =  posts;
      posts = posts->nextpost;
      free(auxPosts);     
    }
    free(aux->posts); // libera o cabeça

    friends = aux->friends->nextFriend;
    while (friends != aux->friends)
    {
      auxFriends = friends;
      friends = friends->nextFriend;
      free(auxFriends);
    }
    free(aux->friends);
    

    messages = aux->messages->nextMessage;
    while (messages != NULL)
    {
      auxMessages = messages;
      messages = messages->nextMessage;
      free(auxMessages);
    }
    free(aux->messages);
    free(aux);
  }
  free(head);
}

void freeGroups(group *head){
  group *p = head->nextGroup; //primeiro cara
  group *aux = NULL;

  friends *auxMembers = NULL;
  friends *members = NULL;

  posts *auxPosts = NULL;
  posts *posts = NULL;

  while (p != head)
  {
    aux = p;
    p = p->nextGroup;

    posts = aux->posts->nextpost;
    while (posts != NULL)
    {
      auxPosts = posts;
      posts = posts->nextpost;
      free(auxPosts);
    }
    free(aux->posts);
    
    members = aux->members->nextFriend;
    while (members != aux->members)
    {
      auxMembers = members;
      members = members->nextFriend;
      free(auxMembers);
    }
    free(aux->members);
    free(aux);

  }
  free(head);
}

int main()
{
  char userName[21];
  char password[21];
  char fullName[250];
  char socialOccupation[251];
  char Adress[251];
  char Biography[251];
  char optionRegister[10];
  char postText[1025];
  char findUserName[21];
  char messageText[251];
  char groupName[51];
  char description[251];

  user *headUser = malloc(sizeof(user));
  headUser->next = headUser;
  headUser->prev = headUser;

  group *headGroup = malloc(sizeof(group));
  headGroup->nextGroup = headGroup;
  headGroup->previosGroup = headGroup;

  user *hasUser = NULL;
  user *hasFindUser = NULL;
  friends *hasFindFriend = NULL;
  group *hasGroup = NULL;

  int start = 0;
  int back = 0;
  int login = 0;
  int option = 0;
 

  do
  {
    printf("1 - Criar uma conta.\n");
    printf("2 - Logar com uma conta já existente.\n");
    printf("0 - Sair\n");

    scanf("%d", &start);
    setbuf(stdin, keyboard);
    system("cls || clear");

    switch (start)
    {
    case 1: //Criar Conta
      userName[0] = '\0';
      printf("Digite o nome de Usuário. (max. de 20 caracteres)\n");
      scanf("%20[^\n]", userName);
      setbuf(stdin, keyboard);

      hasUser = findUser(headUser, userName);

      while (hasUser != headUser && strcmp(userName, hasUser->user_name) == 0)
      {
        userName[0] = '\0';
        system("cls || clear");
        printf("Nome de usuário já cadastrado.\n");
        printf("Digite novamente o nome de usuário ou 'sair' para voltar. (max. de 20 caracteres e sem espaço)\n");
        scanf("%20[^\n]", userName);
        setbuf(stdin, keyboard);
        if (needBack(userName) == 1)
        {
          back = 1;
          break;
        }
        hasUser = findUser(headUser, userName);
      }
      if (back == 1)
      {
        back = 0;
        break;
      }
      password[0] = '\0';
      printf("Digite sua Senha (max. de 20 caracteres e sem espaço)\n");
      scanf("%20[^\n]", password);
      setbuf(stdin, keyboard);

      while (strlen(password) < 5)
      {
        password[0] = '\0';
        system("cls || clear");
        printf("A senha deve conter mais de 4 caracteres.\n");
        printf("Digite novamente a senha ou 'sair' voltar. (max. de 20 caracteres e sem espaço)\n");
        scanf("%20[^\n]", password);
        setbuf(stdin, keyboard);
        if (needBack(password) == 1)
        {
          back = 1;
          break;
        }
      }
      if (back == 1)
      {
        back = 0;
        break;
      }

      system("cls || clear");
      printf("Seu nome de usuário é: %s\n", userName);
      printf("E sua senha é: %s\n", password);
      printf("Se tiver alguma divergencia com o que digitou, lembre-se que só será validado os primeiros 20 caracteres.\n");
      printf("Se quiser refazer o processo não concluindo seu registro digite 'sair'.\n");
      printf("Se quiser registrar sua conta digite qualquer outra coisa.\n");
      scanf("%4s", optionRegister);
      setbuf(stdin, keyboard);
      if (needBack(optionRegister) == 1)
      {
        break;
      }
      system("cls || clear");
      registerUser(headUser, userName, password);

      break;

    case 2: //Fazer Login
      userName[0] = '\0';
      printf("Digite o nome de usuário.\n");
      scanf("%20[^\n]", userName);
      setbuf(stdin, keyboard);

      hasUser = findUser(headUser, userName);

      while (hasUser == headUser || strcmp(userName, hasUser->user_name) != 0)
      {
        userName[0] = '\0';
        system("cls || clear");
        printf("Nome de usuário não encontrado.\n");
        printf("Digite novamente outro nome de usuário ou digite 'sair' para voltar.\n");
        scanf("%20[^\n]", userName);
        setbuf(stdin, keyboard);
        if (needBack(userName) == 1)
        {
          back = 1;
          break;
        }
        hasUser = findUser(headUser, userName);
      }
      if (back == 1)
      {
        back = 0;
        break;
      }
      password[0] = '\0';
      printf("Digite sua Senha\n");
      scanf("%20[^\n]", password);
      setbuf(stdin, keyboard);
      while (strcmp(hasUser->password, password) != 0)
      {
        password[0] = '\0';
        system("cls || clear");
        printf("Senha incorreta, tente novamente!\n");
        printf("Ou digite 'sair' para voltar.\n");
        scanf("%20[^\n]", password);
        setbuf(stdin, keyboard);
        if (needBack(password) == 1)
        {
          back = 1;
          break;
        }
      }
      if (back == 1)
      {
        back = 0;
        break;
      }

      do
      {
        printf("Seja bem vindo(a) %s você está logado(a)!\n", userName);
        printf("1 - Perfil.\n");
        printf("2 - Mural.\n");
        printf("3 - Amigos.\n");
        printf("4 - Mensagens.\n");
        printf("5 - Trocar a Senha.\n");
        printf("6 - Grupos.\n");
        printf("0 - Deslogar.\n");

        scanf("%d", &login);
        setbuf(stdin, keyboard);
        system("cls || clear");

        switch (login)
        {
        case 1:

          do
          {
            printf("1 - Visualizar perfil de algum usuário.\n");
            printf("2 - Editar seu próprio perfil.\n");
            printf("0 - Voltar.\n");

            scanf("%d", &option);
            setbuf(stdin, keyboard);
            system("cls || clear");

            switch (option)
            {
            case 1:
              system("cls || clear");
              findUserName[0] = '\0';
              printf("Digite o nome do usuário que deseja ver o mural. (Podendo ser até mesmo o seu)\n");
              scanf("%20[^\n]", findUserName);
              setbuf(stdin, keyboard);

              hasFindUser = findUser(headUser, findUserName);

              while (hasFindUser == headUser || strcmp(findUserName, hasFindUser->user_name) != 0)
              {
                findUserName[0] = '\0';
                system("cls || clear");
                printf("Nome de usuário não encontrado.\n");
                printf("Digite novamente outro nome de usuário ou digite 'sair' para voltar.\n");
                scanf("%20[^\n]", findUserName);
                setbuf(stdin, keyboard);
                if (needBack(findUserName) == 1)
                {
                  back = 1;
                  break;
                }
                hasFindUser = findUser(headUser, findUserName);
              }
              if (back == 1)
              {
                back = 0;
                break;
              }

              printPerfil(hasFindUser);

              break;

            case 2:
              while (1)
              {
                fullName[0] = '\0';
                socialOccupation[0] = '\0';
                Adress[0] = '\0';
                Biography[0] = '\0';
                system("cls || clear");
                printf("Qual é o seu nome completo? (max. de 250 caracteres)\n");
                scanf("%250[^\n]", fullName);
                setbuf(stdin, keyboard);

                printf("Qual é sua ocupação social? (max. de 250 caracteres)\n");
                scanf("%250[^\n]", socialOccupation);
                setbuf(stdin, keyboard);

                printf("Qual é o seu endereço? (max. de 250 caracteres)\n");
                scanf("%250[^\n]", Adress);
                setbuf(stdin, keyboard);

                printf("Conte um pouco sobre você 'Biografia'. (max. de 250 caracteres)\n");
                scanf("%250[^\n]", Biography);
                setbuf(stdin, keyboard);

              backToTheProfileRegister:
                system("cls ||clear");

                printf("Nome completo: %s\n", fullName);
                printf("Ocupação Social: %s\n", socialOccupation);
                printf("Endereço: %s\n", Adress);
                printf("Biografia: %s\n\n", Biography);
                printf("1 - Seus dados estão corretos e seu perfil pode ser atualizado.\n");
                printf("2 - Refazer.\n");
                printf("0 - Voltar.\n");
                scanf("%d", &option);
                setbuf(stdin, keyboard);
                system("cls || clear");

                if (option == 2)
                {
                  system("cls || clear");
                  continue;
                }
                else if (option == 1)
                {
                  registerPerfil(hasUser, fullName, socialOccupation, Adress, Biography);
                  break;
                }
                else if (option == 0)
                {
                  system("cls ||clear");
                  break;
                }
                else if (option != 1 || option != 2 || option != 0)
                {
                  goto backToTheProfileRegister;
                }
              }
              break;
            }
          } while (option);
          break;

        case 2:
          do
          {
            printf("1 - Criar postagem no seu Mural\n");
            printf("2 - Procurar por um mural\n");
            printf("0 - Voltar\n");
            scanf("%d", &option);
            setbuf(stdin, keyboard);
            system("cls || clear");

            switch (option)
            {
            case 1:
              while (1)
              {
                postText[0] = '\0';
                printf("Digite o seu Post ou digite 'sair' para voltar. (max. 1024 caracteres)\n");
                scanf("%1024[^\n]", postText);
                setbuf(stdin, keyboard);
                if (needBack(postText) == 1)
                {
                  break;
                }
              backToPostRegisterOption:
                system("cls || clear");
                printf("O seu post está correto?\n\n");
                printf("%s\n\n", postText);

                printf("1 - Confirmar e fazer o post.\n");
                printf("2 - Refazer o post.\n");
                printf("0 - Voltar.\n");
                scanf("%d", &option);
                setbuf(stdin, keyboard);
                if (option == 1)
                {
                  system("cls || clear");
                  MakePost(hasUser, postText);
                  break;
                }
                else if (option == 2)
                {
                  system("cls || clear");
                  continue;
                }
                else if (option == 0)
                {
                  system("cls || clear");
                  break;
                }
                else if (option != 0 || option != 1 || option != 2)
                {
                  goto backToPostRegisterOption;
                }
              }

              break;

            case 2:
              system("cls || clear");
              findUserName[0] = '\0';
              printf("Digite o nome do usuário que deseja ver o mural. (Podendo ser até mesmo o seu)\n");
              scanf("%20[^\n]", findUserName);
              setbuf(stdin, keyboard);

              hasFindUser = findUser(headUser, findUserName);

              while (hasFindUser == headUser || strcmp(findUserName, hasFindUser->user_name) != 0)
              {
                findUserName[0] = '\0';
                system("cls || clear");
                printf("Nome de usuário não encontrado.\n");
                printf("Digite novamente outro nome de usuário ou digite 'sair' para voltar.\n");
                scanf("%20[^\n]", findUserName);
                setbuf(stdin, keyboard);
                if (needBack(findUserName) == 1)
                {
                  back = 1;
                  break;
                }
                hasFindUser = findUser(headUser, findUserName);
              }
              if (back == 1)
              {
                back = 0;
                break;
              }

              printPosts(hasFindUser);

              break;

            } // final do switch

          } while (option);
          break;

        case 3:
          do
          {
            printf("1 - Adcionar novos amigos\n");
            printf("2 - Visualizar lista de amigos\n");
            printf("0 - Voltar\n");

            scanf("%d", &option);
            setbuf(stdin, keyboard);
            system("cls || clear");

            switch (option)
            {
            case 1:
              system("cls || clear");
              findUserName[0] = '\0';
              printf("Digite o nome do usuário que deseja adcionar como amigo.\n");
              scanf("%20[^\n]", findUserName);
              setbuf(stdin, keyboard);

              hasFindUser = findUser(headUser, findUserName);

              while (hasFindUser == headUser || strcmp(findUserName, hasFindUser->user_name) != 0 || strcmp(hasUser->user_name, findUserName) == 0)
              {
                findUserName[0] = '\0';
                system("cls || clear");
                printf("Nome de usuário não encontrado ou você digitou seu próprio nome.\n");
                printf("Digite novamente outro nome de usuário ou digite 'sair' para voltar.\n");
                scanf("%20[^\n]", findUserName);
                setbuf(stdin, keyboard);
                if (needBack(findUserName) == 1)
                {
                  back = 1;
                  break;
                }
                hasFindUser = findUser(headUser, findUserName);
              }
              if (back == 1)
              {
                back = 0;
                break;
              }
              addFriend(hasFindUser->friends, hasUser->user_name);
              addFriend(hasUser->friends, hasFindUser->user_name);

              break;

            case 2:

              system("cls || clear");
              findUserName[0] = '\0';
              printf("Digite o nome do usuário que deseja ver a lista de amigo. (Podendo ser o seu também)\n");
              scanf("%20[^\n]", findUserName);
              setbuf(stdin, keyboard);

              hasFindUser = findUser(headUser, findUserName);

              while (hasFindUser == headUser || strcmp(findUserName, hasFindUser->user_name) != 0)
              {
                findUserName[0] = '\0';
                system("cls || clear");
                printf("Nome de usuário não encontrado.\n");
                printf("Digite novamente outro nome de usuário ou digite 'sair' para voltar.\n");
                scanf("%20[^\n]", findUserName);
                setbuf(stdin, keyboard);
                if (needBack(findUserName) == 1)
                {
                  back = 1;
                  break;
                }
                hasFindUser = findUser(headUser, findUserName);
              }
              if (back == 1)
              {
                back = 0;
                break;
              }
              system("cls || clear");
              printf("Lista de amigos:\n");
              printFriends(hasFindUser->friends);

              break;
            }

          } while (option);
          break;

        case 4:
          do
          {
            printf("1 - Mandar mensagens para seus amigos\n");
            printf("2 - Caixa de entrada\n");
            printf("0 - Voltar\n");
            scanf("%d", &option);
            setbuf(stdin, keyboard);

            switch (option)
            {
            case 1:
              system("cls || clear");
              findUserName[0] = '\0';
              printf("Lista de amigos:\n");
              printFriends(hasUser->friends);
              printf("Digite o nome do amigo que deseja enviar uma mensagem.\n");
              scanf("%20[^\n]", findUserName);
              setbuf(stdin, keyboard);

              hasFindFriend = findFriend(hasUser->friends, findUserName);

              while (hasFindFriend == hasUser->friends || strcmp(findUserName, hasFindFriend->name) != 0)
              {
                findUserName[0] = '\0';
                system("cls || clear");
                printf("Nome de usuário não encontrado ou você digitou seu próprio nome.\n");
                printf("Digite novamente outro nome de usuário ou digite 'sair' para voltar.\n");
                scanf("%20[^\n]", findUserName);
                setbuf(stdin, keyboard);
                if (needBack(findUserName) == 1)
                {
                  back = 1;
                  break;
                }
                hasFindFriend = findFriend(hasUser->friends, findUserName);
              }
              if (back == 1)
              {
                back = 0;
                break;
              }

              hasFindUser = findUser(headUser, findUserName);
              printf("Digite a mensagem que deseja enviar.\n");
              scanf("%250[^\n]", messageText);
              setbuf(stdin, keyboard);
              SendMessage(hasFindUser, messageText, hasUser->user_name);
              break;

            case 2:
              printf("Sua caixa de entrada:\n\n");
              printMessages(hasUser);
              break;
            }
          } while (option);
          break;

        case 5:
          password[0] = '\0';
          printf("Digite a sua Senha atual para prosseguir.\n");
          scanf("%20[^\n]", password);
          setbuf(stdin, keyboard);

          while (strcmp(hasUser->password, password) != 0)
          {
            password[0] = '\0';
            system("cls || clear");
            printf("Senha incorreta, tente novamente!\n");
            printf("Ou digite 'sair' para voltar.\n");
            scanf("%20[^\n]", password);
            setbuf(stdin, keyboard);
            if (needBack(password) == 1)
            {
              back = 1;
              break;
            }
          }
          if (back == 1)
          {
            back = 0;
            break;
          }

          printf("Digite a nova senha que deseja.\n");
          scanf("%20[^\n]", password);
          setbuf(stdin, keyboard);

          while (strlen(password) < 5)
          {
            password[0] = '\0';
            system("cls || clear");
            printf("A senha deve conter mais de 4 caracteres.\n");
            printf("Digite novamente a senha ou 'sair' voltar. (max. de 20 caracteres e sem espaço)\n");
            scanf("%20[^\n]", password);
            setbuf(stdin, keyboard);
            if (needBack(password) == 1)
            {
              back = 1;
              break;
            }
          }
          if (back == 1)
          {
            back = 0;
            break;
          }

          strcpy(hasUser->password, password);
          printf("Senha trocada com sucesso.\n");

          break;
        case 6:
          do
          {
            printf("1 - Criar um grupo.\n");
            printf("2 - Entrar em um grupo.\n");
            printf("3 - Fazer post em algum grupo.\n");
            printf("4 - Ver postagens dos grupos.\n");
            printf("5 - Ver membros de algum grupo.\n");
            printf("6 - Ver lista de grupos.\n");
            printf("0 - Voltar.\n");
            scanf("%d", &option);
            setbuf(stdin, keyboard);
            system("cls || clear");

            switch (option)
            {
            case 1:
              while (1)
              {
                groupName[0] = '\0';
                description[0] = '\0';
                printf("Digite o nome do grupo. (max. de 50 caracteres)\n");
                scanf("%50[^\n]", groupName);
                setbuf(stdin, keyboard);

                printf("Digite a descrição do grupo. (max. de 250 catacteres)\n");
                scanf("%250[^\n]", description);
                setbuf(stdin, keyboard);

              backToRegisterGroupOption:
                system("cls || clear");
                printf("Nome do grupo: %s\n", groupName);
                printf("Descrição: %s\n\n", description);
                printf("1 - Dados estão corretos criar grupo.\n");
                printf("2 - Refazer.\n");
                printf("0 - Voltar.\n");
                scanf("%d", &option);
                setbuf(stdin, keyboard);

                if (option == 1)
                {
                  createGroup(headGroup, groupName, hasUser->user_name, description);
                  break;
                }
                else if (option == 2)
                {
                  system("cls || clear");
                  continue;
                }
                else if (option == 0)
                {
                  system("cls || clear");
                  break;
                }
                else if (option != 1 || option != 2 || option != 0)
                {
                  goto backToRegisterGroupOption;
                }
              }
              break;

            case 2:
              printGroups(headGroup);
              groupName[0] = '\0';
              printf("Digite o nome do grupo em que deseja entrar.\n");
              scanf("%50[^\n]", groupName);
              setbuf(stdin, keyboard);

              hasGroup = findGroup(headGroup, groupName);

              while (hasGroup == headGroup || strcmp(groupName, hasGroup->groupName) != 0)
              {
                groupName[0] = '\0';
                system("cls || clear");
                printf("Grupo não encontrado.\n");
                printf("Digite novamente o nome do grupo ou 'sair' para voltar. (max. de 50 caracteres)\n");
                scanf("%20[^\n]", groupName);
                setbuf(stdin, keyboard);
                if (needBack(groupName) == 1)
                {
                  back = 1;
                  break;
                }
                hasGroup = findGroup(headGroup, groupName);
              }
              if (back == 1)
              {
                back = 0;
                break;
              }
            backToIncludeMemberOption:
              system("cls ||  clear");
              printf("Grupo: %s\n", hasGroup->groupName);
              printf("Líder: %s\n", hasGroup->leaderName);
              printf("Descrição: %s\n\n", hasGroup->description);
              printf("1 - Confirmar e entrar no grupo\n");
              printf("0 - Voltar\n");
              scanf("%d", &option);
              setbuf(stdin, keyboard);
              if (option == 1)
              {
                system("cls || clear");
                includeMenber(hasGroup->members, hasUser->user_name);
                break;
              }
              else if (option == 0)
              {
                system("cls || clear");
                break;
              }
              else if (option != 0 || option != 1)
              {
                system("cls || clear");
                goto backToIncludeMemberOption;
              }
              break;

            case 3:
              while (1)
              {
                printGroups(headGroup);
                groupName[0] = '\0';
                printf("Digite o nome do grupo em que deseja fazer uma postagem.\n");
                scanf("%50[^\n]", groupName);
                setbuf(stdin, keyboard);

                hasGroup = findGroup(headGroup, groupName);

                while (hasGroup == headGroup || strcmp(groupName, hasGroup->groupName) != 0)
                {
                  groupName[0] = '\0';
                  system("cls || clear");
                  printf("Grupo não encontrado.\n");
                  printf("Digite novamente o nome do grupo ou 'sair' para voltar. (max. de 50 caracteres)\n");
                  scanf("%20[^\n]", groupName);
                  setbuf(stdin, keyboard);
                  if (needBack(groupName) == 1)
                  {
                    back = 1;
                    break;
                  }
                  hasGroup = findGroup(headGroup, groupName);
                }
                if (back == 1)
                {
                  back = 0;
                  break;
                }

                hasFindFriend = findFriend(hasGroup->members, hasUser->user_name);

                if (hasFindFriend == hasGroup->members || strcmp(hasFindFriend->name, hasUser->user_name) != 0)
                {
                  printf("Você ainda não faz parte desse grupo.\n");
                  continue;
                }

                system("cls || clear");
                postText[0] = '\0';
                printf("Digite o seu post ou digite 'sair' para voltar. (max. de 250 caracteres)\n");
                scanf("%250[^\n]", postText);
                setbuf(stdin, keyboard);
                if (needBack(postText) == 1)
                {
                  break;
                }

              backToPostGroupOption:
                system("cls || clear");
                printf("Seu post: %s\n\n", postText);
                printf("1 - Confirmar e fazer post.\n");
                printf("2 - Refazer\n");
                printf("0  - Voltar\n");
                scanf("%d", &option);
                setbuf(stdin, keyboard);

                if (option == 1)
                {
                  system("cls || clear");
                  MakePostGroup(hasUser, hasGroup, postText);
                  break;
                }
                else if (option == 2)
                {
                  system("cls || clear");
                  continue;
                }
                else if (option == 0)
                {
                  system("cls || clear");
                  break;
                }
                else if (option != 1 || option != 2 || option != 0)
                {
                  goto backToPostGroupOption;
                }
              }

              break;

            case 4:
              printGroups(headGroup);
              groupName[0] = '\0';
              printf("Digite o nome do grupo que deseja ver as postagens.\n");
              scanf("%50[^\n]", groupName);
              setbuf(stdin, keyboard);

              hasGroup = findGroup(headGroup, groupName);

              while (hasGroup == headGroup || strcmp(groupName, hasGroup->groupName) != 0)
              {
                groupName[0] = '\0';
                system("cls || clear");
                printf("Grupo não encontrado.\n");
                printf("Digite novamente o nome do grupo ou 'sair' para voltar. (max. de 50 caracteres)\n");
                scanf("%20[^\n]", groupName);
                setbuf(stdin, keyboard);
                if (needBack(groupName) == 1)
                {
                  back = 1;
                  break;
                }
                hasGroup = findGroup(headGroup, groupName);
              }
              if (back == 1)
              {
                back = 0;
                break;
              }

              printPostsGroup(hasGroup);
              break;

            case 5:
              system("cls || clear");
              printGroups(headGroup);
              printf("Digite o nome do grupo que deseja ver os membros\n");
              scanf("%50[^\n]", groupName);
              setbuf(stdin, keyboard);

              hasGroup = findGroup(headGroup, groupName);

              while (hasGroup == headGroup || strcmp(groupName, hasGroup->groupName) != 0)
              {
                groupName[0] = '\0';
                system("cls || clear");
                printf("Grupo não encontrado.\n");
                printf("Digite novamente o nome do grupo ou 'sair' para voltar. (max. de 50 caracteres)\n");
                scanf("%20[^\n]", groupName);
                setbuf(stdin, keyboard);
                if (needBack(groupName) == 1)
                {
                  back = 1;
                  break;
                }
                hasGroup = findGroup(headGroup, groupName);
              }
              if (back == 1)
              {
                back = 0;
                break;
              }
              system("cls || clear");
              printf("Membros:\n");
              printFriends(hasGroup->members);

              break;

            case 6:
              printGroups(headGroup);

              break;
            }
          } while (option);

          break;
        }

      } while (login);
      break;
    }
  } while (start);

  freeUsers(headUser);
  freeGroups(headGroup);

  return 0;
}
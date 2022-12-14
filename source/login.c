#include <stdio.h>

#include "globais.h"
#include "login.h"
#include "search.h"

void login() {

  char usuario[50], senha[30];
  Usuario user_found = USER_NOT_FOUND;

  while (is_string_equal(user_found.nome, "false")) {
    clean_console();

    printf("\nInsira suas informações: \n\n");

    inputString(usuario, "CPF/Email: ");
    inputString(senha, "Senha: ");

    user_found = busca_usuario(usuario, 1);

    if (!is_valid_user(user_found) ||
        !is_string_equal(user_found.senha, senha)) {
      user_found = USER_NOT_FOUND;
      printf("\nUsuario ou senha incorretos!");
      continue;
    }

    usuario_logado = &usuarios[user_found.id];
  }
}

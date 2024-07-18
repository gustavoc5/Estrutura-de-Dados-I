// TAD para Playlist Dinâmica Duplamente Encadeada Circular

#ifndef _PLAYLIST_DDEC
#define _PLAYLIST_DDEC

typedef struct elemento *Playlist;
typedef struct musica Musica;

// funções para alocar e desalocar memória
Playlist *criar_playlist();
int liberar_playlist(Playlist *pl);

// funções para obter informações da playlist
int tamanho_playlist(Playlist *pl);
int playlist_vazia(Playlist *pl);
int playlist_cheia(Playlist *pl);

// funções para inserção de elementos da playlist
int inserir_playlist_inicio(Playlist *pl, Musica *dado);
int inserir_playlist_final(Playlist *pl, Musica *dado);
int inserir_playlist_ordenada(Playlist *pl, Musica *dado);

// funções para remoção de elementos da playlist
int remover_playlist_inicio(Playlist *pl);
int remover_playlist_final(Playlist *pl);
int remover_playlist_meio(Playlist *pl, char *nome);

// funções para buscar elementos na playlist
int buscar_playlist_posicao(Playlist *pl, int pos, Musica *dado);
int buscar_playlist_nome(Playlist *pl, char *nome, int *pos);

// funções para impressão de dados da playlist
int imprimir_playlist(Playlist *pl);
int imprimir_dado(Musica *dado);

// função para definir a posição correta da playlist
int posicao_playlist(Playlist *pl, int *posi, Musica *dado);

#endif

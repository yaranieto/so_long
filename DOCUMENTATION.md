# Documentación del Proyecto so_long

## Estructuras Principales

### t_img_instance
```c
typedef struct s_img_instance {
    mlx_image_t *img;        // Puntero a la imagen MLX42
    int32_t instance_id;     // ID de la instancia de la imagen
} t_img_instance;
```

### t_map
```c
typedef struct s_map {
    char **map;              // Array 2D que contiene el mapa
    int width;              // Ancho del mapa
    int height;             // Alto del mapa
    int total_collectibles; // Total de coleccionables en el mapa
    int num_collectibles;   // Número de coleccionables recogidos
    int tile_size;         // Tamaño de cada casilla (64 píxeles)
    int offset_x;          // Desplazamiento en X para centrar
    int offset_y;          // Desplazamiento en Y para centrar
} t_map;
```

### t_game
```c
typedef struct s_game {
    mlx_t *mlx;           // Instancia principal de MLX42
    t_map map;            // Estructura del mapa
    t_img_instance player;    // Sprite del jugador
    t_img_instance wall;      // Sprite de la pared
    t_img_instance collectible; // Sprite del coleccionable
    t_img_instance exit;      // Sprite de la salida
    t_img_instance floor;     // Sprite del suelo
    int player_x;         // Posición X del jugador
    int player_y;         // Posición Y del jugador
    int steps;           // Contador de pasos dados
} t_game;
```

## Funciones Principales

### Funciones de Inicio
- `start_game(t_game *game)`: Inicializa el juego, crea la ventana y configura los hooks de eventos.
- `load_images(t_game *game)`: Carga las texturas principales (jugador, salida).
- `load_images_extra(t_game *game)`: Carga las texturas adicionales (coleccionables, suelo).

### Funciones de Renderizado
- `render_map(t_game *game)`: Renderiza el mapa completo en el siguiente orden:
  1. Suelo (floor)
  2. Paredes (walls)
  3. Coleccionables (collectibles)
  4. Salida (exit)
  5. Jugador (player)

### Funciones de Movimiento
- `move_player(t_game *game, int dx, int dy)`: Maneja el movimiento del jugador
  - Comprueba colisiones
  - Actualiza la posición
  - Gestiona la recolección de items
  - Actualiza el contador de pasos
  - Comprueba condición de victoria

### Funciones de Control
- `key_hook(mlx_key_data_t keydata, void *param)`: Maneja los eventos de teclado
  - WASD: Movimiento
  - ESC: Salir del juego

### Funciones de Validación del Mapa
- `validate_map(t_map *map)`: Valida que el mapa cumpla todos los requisitos:
  - Forma rectangular
  - Rodeado de paredes
  - Contiene 1 jugador (P)
  - Contiene 1 salida (E)
  - Contiene al menos 1 coleccionable (C)

- `flood_fill(char **map, t_map map_info, int y, int x)`: Verifica que se pueda llegar a todos los coleccionables y a la salida.

### Funciones de Utilidad
- `error_exit(const char *message)`: Muestra un mensaje de error y cierra el programa
- `close_window(void *param)`: Cierra la ventana y libera la memoria
- `player_position(t_map *map, t_game *game)`: Encuentra la posición inicial del jugador

## Elementos del Mapa
- `0`: Suelo transitable
- `1`: Pared
- `C`: Coleccionable
- `E`: Salida
- `P`: Posición inicial del jugador

## Sistema de Control
- `W`: Mover arriba
- `A`: Mover izquierda
- `S`: Mover abajo
- `D`: Mover derecha
- `ESC`: Salir del juego

## Condición de Victoria
El juego se gana cuando:
1. Se han recogido todos los coleccionables
2. El jugador llega a la salida
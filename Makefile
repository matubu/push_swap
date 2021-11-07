BIN = bin
FLAGS = -Wall -Wextra -Werror 

SRCS = split lst stack math stack_oper lst_oper lst_get optimize cost str
MANDATORY = push_swap
BONUS = checker
OBJ_BOTH = $(foreach src,$(SRCS),$(BIN)/$(src).o)

NAME = $(MANDATORY)

ECHO = echo
RED = \033[31m
GRE = \033[32m
GRA = \033[37m
BLU = \033[34m
EOC = \033[0m

all: $(NAME)

bin/%.o: %.c
	@$(ECHO) "$(BLU)● Compiling $^ 🔧$(EOC)"
	@mkdir -p $(BIN)
	@gcc $(FLAGS) -c $^ -o $@

$(NAME): $(OBJ_BOTH) $(BIN)/$(MANDATORY).o
	@$(ECHO) "$(GRE)● Compiling $@ ⚙️ $(EOC)"
	@gcc $(FLAGS) $^ -o $@

clean:
	@$(ECHO) "$(RED)● Removing /$(BIN) 📁$(EOC)"
	@rm -rf $(BIN)

fclean: clean
	@$(ECHO) "$(RED)● Removing binary ⚙️ $(EOC)"
	@rm -rf $(MANDATORY) $(BONUS)

re: fclean all

bonus: $(BONUS)

$(BONUS): $(OBJ_BOTH)  $(BIN)/$(BONUS).o
	@$(ECHO) "$(GRE)● Compiling $@ ⚙️ $(EOC)"
	@gcc $(FLAGS) $^ -o $@

score: all
	@./push_swap 9 8 6 1 7 | wc -l
	@./push_swap 41 57 81 67 4 21 15 88 32 53 97 99 49 8 73 29 33 80 37 22 31 65 87 60 69 66 45 47 34 23 92 17 64 2 61 42 54 95 7 11 70 35 24 12 96 44 20 71 46 89 19 82 56 86 5 39 43 28 36 72 83 40 59 58 100 25 55 85 77 63 9 76 26 38 84 3 50 27 1 51 18 90 6 68 74 13 93 91 75 16 14 10 78 94 79 52 48 30 98 62 | wc -l
	@./push_swap 150 295 225 4 445 53 489 209 183 35 236 368 297 366 93 359 68 59 360 270 227 136 336 80 128 31 350 324 121 99 198 335 120 37 12 158 186 33 435 276 305 32 25 224 218 196 456 82 311 439 94 321 13 108 219 169 392 27 10 419 430 498 481 212 385 95 391 277 23 434 443 207 26 135 278 442 279 132 145 486 379 43 142 193 283 299 222 55 475 24 46 428 201 376 367 228 322 199 472 272 393 208 220 269 254 122 60 327 177 261 377 474 273 318 204 96 88 345 469 466 451 104 119 259 41 6 265 253 400 298 462 164 449 262 110 363 190 461 373 365 354 440 109 314 340 243 11 50 124 159 144 497 274 258 14 467 372 170 139 369 181 51 166 446 248 86 444 302 217 156 487 155 476 206 75 231 161 280 304 386 92 432 165 347 404 408 405 294 240 52 495 313 292 176 22 303 246 268 488 346 42 426 91 399 282 134 480 355 131 62 192 374 129 447 250 173 478 455 79 307 271 112 127 406 358 429 29 90 203 308 403 8 19 316 378 471 412 101 125 194 226 235 306 157 172 383 459 436 141 416 151 182 179 47 214 72 15 48 213 126 84 286 328 496 239 58 417 241 115 438 491 238 189 388 61 69 343 500 348 205 342 16 425 167 464 154 260 494 28 402 197 215 162 87 245 453 396 473 34 437 249 89 39 483 364 410 479 289 44 331 398 74 230 221 66 310 293 361 175 407 465 3 454 118 223 257 499 460 352 395 200 137 18 493 332 252 351 281 81 284 266 168 1 337 237 421 233 147 320 353 448 133 317 285 140 492 98 356 148 114 130 202 341 216 477 329 185 195 401 138 146 330 420 38 76 375 56 338 349 9 296 390 152 267 418 333 309 334 113 143 482 450 470 163 17 300 180 485 105 339 397 178 422 371 77 211 210 83 251 64 457 413 234 21 188 232 2 67 184 36 57 290 411 5 97 463 174 63 323 484 100 117 387 73 458 111 384 409 171 20 291 468 427 490 319 431 116 65 106 49 103 381 301 452 315 415 40 242 263 433 394 389 45 54 78 256 423 344 153 149 414 288 30 191 287 244 160 441 71 362 325 264 229 85 123 326 275 70 247 312 380 7 255 107 357 424 382 187 102 370 | wc -l
	@./push_swap `ruby -e "puts (1..5).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l

.PHONY: all bonus clean fclean re bonus score

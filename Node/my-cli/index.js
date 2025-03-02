#!/usr/bin/env node

const printFive = async (name) => {
  const response = await fetch(`https://pokeapi.co/api/v2/pokemon/${name}`);
  const pokemon = await response.json();
  const moves = pokemon.moves.map(({ move }) => move.name);
  console.log(moves.slice(0, 5));
};

printFive("charmander");

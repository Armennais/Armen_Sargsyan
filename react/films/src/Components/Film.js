import React, { useState } from "react";
import "../styles/Film.css";
import Button from "./Buttonn";
import { Link } from "react-router-dom";
const Film = ({ elem, onClick }) => {
  const listItems = elem.map((e) => (
    <li key={e.id}>
      <h1>{e.title}</h1>
      <img src={e.img} />
      <p>{e.description.substring(0, 5).concat("...")}</p>
      <Button
        value="Delete"
        onClick={() => {
          onClick(e.id);
        }}
      />
      <Link className="more" to={`${e.id}`}>
        more...
      </Link>
    </li>
  ));
  return (
    <div className="film-container">
      <ul className="list-group">{listItems}</ul>
    </div>
  );
};

export default Film;

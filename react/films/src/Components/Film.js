import React, { useState } from 'react';
import ReactDOM from 'react-dom/client';
import '../styles/Film.css';
import Button from './Buttonn';
import list from './FilmsList'
import {Link} from 'react-router-dom'
const Film = ({elem,onClick}) => {

    

    const listItems = elem.map((e) =>
        <li>
            
            <h1>{e.title}</h1>
            <img src={e.img}/>
            <p>{e.description}</p>
            <Button value = "Delete" onClick={()=>{onClick(e.id)}} />
            <Link key={e.id} to={`/film/${e.id}`}>GO TO</Link>
        </li>
    );
    return( 
        <div  className="film-container">
            <ul  className="list-group">{listItems}</ul>


        </div>
    )
}



export default Film;
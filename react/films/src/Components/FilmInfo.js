import React, { useState } from "react";
import {useParams} from 'react-router-dom'
import list from "./FilmsList";
import '../styles/FilmInfo.css';
import { filtredList} from "../App";
const FilmInfo = () =>{
    const {id} = useParams();
    return(
        <div className="descDiv" key={id}>
            <h1 className="descTitle">
                {filtredList[id].title}
            </h1>
            <img className="descImg" src={filtredList[id].img}/>
            <p className="descParag">{filtredList[id].description}</p>
        </div>
        
    )
}
export default FilmInfo
import {Link,Outlet} from 'react-router-dom'
import '../styles/index.css';

const Layout = () => {
    return(
        <>
            <nav className='navbar'>
                <Link to="/">HOME</Link>
                <Link to="/films">FILMS</Link>
            </nav> 
            <Outlet />
        </>
    )
}
export default Layout
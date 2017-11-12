import React, { Component } from 'react'
import { bindActionCreators } from 'redux'
import { connect } from 'react-redux'

import Navbar from './navbar'
import Nav from './nav'
import NavItem from './navItem'

import { selectItem } from '../item/itemActions'

class Header extends Component {
    render() {
        const selected = this.props.item.selected === this.props.target
        return (
            <header className='main-header'>
                <a href={this.props.path} className='logo'
                    data-toggle='item'
                    onClick={() => this.props.selectItem(this.props.target)}
                    data-target={this.props.target}>
                    <span className='logo-mini'><i className='icon-station_icon'></i></span>
                    <span className='logo-lg'>
                        <i className='icon-station_icon'></i>
                        <b>Code</b> Station
                    </span>        
                </a>
                <nav className='navbar navbar-static-top'>
                    <a href className='sidebar-toggle' data-toggle='offcanvas'></a>
                    <Navbar>
                        <Nav>
                            <NavItem icon='fa fa-folder-open-o' />
                            <NavItem icon='fa fa-floppy-o' />
                        </Nav>
                    </Navbar>
                </nav>
        </header>
        )
    }
}

const mapStateToProps = state => ({item : state.item})
const mapDispatchToProps = dispatch => bindActionCreators({selectItem}, dispatch)
export default connect(mapStateToProps, mapDispatchToProps)(Header)

/*
export default props => (
    <header className='main-header'>
        <a href='/#/' className='logo'>
            <span className='logo-mini'><i className='icon-station_icon'></i></span>
            <span className='logo-lg'>
                <i className='icon-station_icon'></i>
                <b>Code</b> Station
            </span>        
        </a>
        <nav className='navbar navbar-static-top'>
            <a href className='sidebar-toggle' data-toggle='offcanvas'></a>
        </nav>
    </header>
)
*/
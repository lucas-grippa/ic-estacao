import React, { Component } from 'react'
import { bindActionCreators } from 'redux'
import { connect } from 'react-redux'

class ItemContent extends Component {
    render () {
        const selected = this.props.item.selected === this.props.id
        return (
            <div id={this.props.id}
                 className={`tab-pane ${selected? 'active' : ''}`}>
                {this.props.children}
            </div>
        )
    }
}

const mapStateToProps = state => ({item: state.item})
export default connect(mapStateToProps)(ItemContent)
//
//  ViewController.swift
//  pixscape-ios
//
//  Created by bils on 01/12/2018.
//  Copyright © 2018 Scape Technologies. All rights reserved.
//

import UIKit
import ScapeKit

final class ARViewController: UIViewController {

    lazy var arView: SCKArView = {
        return SCKArView()
    }()
    
    lazy var geoButton: UIButton = {
        let button = UIButton(frame: CGRect(x: self.view.bounds.width/2 - 50,
                                            y: self.view.bounds.height - 50,
                                            width: 100,
                                            height: 50))
        button.backgroundColor = .green
        button.setTitle("Localize", for: .normal)
        button.addTarget(self, action: #selector(localize), for: .touchUpInside)
        return button
    }()
    
    private var arSession: SCKArSession?
    private var geoSession: SCKGeoSession?
    private var scapeClient: SCKScapeClient
    
    init(scapeClient: SCKScapeClient) {
        self.scapeClient = scapeClient
        
        super.init(nibName: nil, bundle: nil)
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        NotificationCenter.default.addObserver(self,
                                               selector: #selector(didBecomeActive),
                                               name: NSNotification.Name(rawValue: UIApplication.didBecomeActiveNotification.rawValue),
                                               object: nil)
        
        self.view.addSubview(arView)
        self.view.addSubview(geoButton)
        
        setupAr()
        setupGeo()
    }
    
    override func viewWillLayoutSubviews() {
        super.viewWillLayoutSubviews()
        
        arView.frame = view.bounds
    }
    
    func setupAr() {
        arSession = scapeClient.arSession?.withArView(view: arView)
        arSession?.setDebugMode(false)
        arSession?.resetTracking()
    }
    
    func setupGeo() {
        geoSession = scapeClient.geoSession
        geoSession?.setGeoSessionObserver(self)
    }
    
    @objc func didBecomeActive() {
        arSession?.resetTracking()
    }
    
    @objc func localize(sender: UIButton!) {
        geoSession?.getCurrentGeoPositionAsync()
    }
}

extension ARViewController: SCKGeoSessionObserver {
    func onGeoSessionStarted(_ session: SCKGeoSession?, details: SCKGeoSessionDetails) {
        
    }
    
    func onGeoSessionClosed(_ session: SCKGeoSession?, details: SCKGeoSessionDetails) {
        
    }
    
    func onGeoSessionError(_ session: SCKGeoSession?, details: SCKGeoSessionDetails) {
        print("Could not retrieve geo coordinates: \(details.errorMessage)")
        
    }
    
    func onGeoPositionRawEstimated(_ session: SCKGeoSession?, details: SCKGeoSessionDetails) {
        let coordinates = "\(details.rawLocation.coordinates.latitude) \(details.rawLocation.coordinates.longitude) \(details.rawLocation.coordinates.altitude) "
        print("Retrieving partial GeoCoordinates: \(coordinates)")
        
        DispatchQueue.main.async {
            self.geoButton.backgroundColor = .blue
        }
    }
    
    func onGeoPositionLocked(_ session: SCKGeoSession?, details: SCKGeoSessionDetails) {
        let coordinates = "\(details.lockedCoordinates.latitude) \(details.lockedCoordinates.longitude) \(details.lockedCoordinates.altitude) "
        print("Retrieving final GeoCoordinates: \(coordinates)")
        
        DispatchQueue.main.async {
            self.geoButton.backgroundColor = .green
        }
    }
}

